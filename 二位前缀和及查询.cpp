#include <stdio.h>
int arr[5001][5001];
int prefix[5001][5001];
void prefix_precessing()
{
	int i,u;
	prefix[0][0]=arr[0][0];
	for(i=1;i<=5000;i++) prefix[0][i]=prefix[0][i-1]+arr[0][i];
	for(i=1;i<=5000;i++) prefix[i][0]=prefix[i-1][0]+arr[i][0];
	for(i=1;i<=5000;i++)
	{
		for(u=1;u<=5000;u++)
		{
			prefix[i][u]=prefix[i-1][u]+prefix[i][u-1]-prefix[i-1][u-1]+arr[i][u];
		}	
	}
	return;	
}
int query(int x1,int y1,int x2,int y2)//查询两个对角坐标是x1 y1(左上角)  x2 y2(右下角)的矩形的价值 
{
    int ans = prefix[x2][y2];
    
    if(x1 > 0) ans -= prefix[x1-1][y2];
    if(y1 > 0) ans -= prefix[x2][y1-1];
    if(x1 > 0 && y1 > 0) ans += prefix[x1-1][y1-1];
    return ans;
}
