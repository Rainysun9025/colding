#include <stdio.h>
#include <string.h>
int n,m;
char arr[15][15];
int kk[15];
int used[15];
int ans=10000000;
int DFS(int cur,int num)
{
	if(cur==m)
	{
		if(num<ans)
		{
			ans=num;
			return 0;
		}
	}
	if(kk[cur]!=0)
	{
		DFS(cur+1,num);return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(used[i]==1) continue;
		if(arr[i][cur]=='x') continue;
		used[i]=1;
		for(int u=0;u<=m;u++)
		{
			if(arr[i][u]=='o') kk[u]++;
		}
		DFS(cur+1,num+1);
		used[i]=0;
		for(int u=0;u<=n;u++)
		{
			if(arr[i][u]=='o') kk[u]--;
		}
	}
	return 0;
}
int main()
{
	scanf("%d %d",&n,&m);
	
	int i,u,l;
	for(i=1;i<=n;i++)
	{
		scanf("%s",arr[i]);
	}
	DFS(0,0);
	printf("%d",ans);
	return 0;
 } 
