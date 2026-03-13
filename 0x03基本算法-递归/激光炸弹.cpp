#include <stdio.h>
int arr[5001][5001];
int prefix[5001][5001];
int left_up;
int left_low;
int right_up;
int right_low;
int compare_min(int a,int b,int c,int d)
{
	int min=a;
	if(b<min) min=b;
	if(c<min) min=c;
	if(d<min) min=d;
	return min;
}
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
int where(int x1,int y1,int x2,int y2)
{
	int temp=query(x1,y1,x2,y2);
	int left,right,up,low;
	left=query(x1,y1,x1,y2);
	right=query(x2,y1,x2,y2);
	up=query(x1,y1,x2,y1);
	low=query(x1,y2,x2,y2);
	left_up=left+up-arr[x1][y1];
	left_low=left+low-arr[x1][y2];
	right_up=right+up-arr[x2][y1];
	right_low=right+low-arr[x2][y2];
	int min=compare_min(left_up,left_low,right_up,right_low);
	return min;
}
int main()
{
	int n,r;
	scanf("%d %d",&n,&r);
	int i,u,l;
	int x,y,v;
	for(i=1;i<=n;i++)
	{
		scanf("%d %d %d",&x,&y,&v);
		arr[x][y]=v;
	}
	prefix_precessing();
	int x1,y1,x2,y2;
	int cur=-1;
	int max=0;
	for(x1=0;x1+r<=5000;x1++)
	{
		for(y1=0;y1+r<=5000;y1++)
		{
			x2=x1+r;
			y2=y1+r;
			cur=query(x1,y1,x2,y2);
			cur=cur-where(x1,y1,x2,y2);
			if(cur>max) max=cur;	
		}
	}
	printf("%d",max);
	return 0;
}
