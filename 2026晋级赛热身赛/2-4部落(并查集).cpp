#include <bits/stdc++.h>
using namespace std;
int arr[10005];
int Size[10005];
int vis[10005];
int n;
int myfind(int x)
{
	if(arr[x]==x) return x;
	else
	{
		return arr[x]=myfind(arr[x]);
	}
}
void Union(int x,int y)
{
	int rootx=myfind(x);
	int rooty=myfind(y);
	if(rootx!=rooty)
	{
		if(Size[rootx]<=Size[rooty])
		{
			arr[rootx]=arr[rooty];
			Size[rooty]+=Size[rootx];
		}
		else
		{
			arr[rooty]=rootx;
			Size[rootx]+=Size[rooty];
		}
	}
	return;
}
int main()
{
	memset(Size,1,sizeof(int)*10005);
	cin>>n;
	for(int i=0;i<10005;i++) arr[i]=i;
	for(int i=1;i<=n;i++)
	{
		int last,cur;
		int p;
		cin>>p;
		for(int u=1;u<=p;u++)
		{
			cin>>cur;
			vis[cur]=1;
			if(u==1) last=cur;
			else
			{
				Union(last,cur);
			}
		}
	}
	int num_ren=0;
	int num_buluo=0;
	for(int i=0;i<10005;i++)
	{
		if(vis[i]==1) num_ren++;
	}
	for(int i=0;i<10005;i++)
	{
		if(vis[i]==1&&arr[i]==i) num_buluo++;
	}
	cout<<num_ren<<" "<<num_buluo<<endl;
	int k;
	cin>>k;
	while(k--)
	{
		int a,b;
		cin>>a>>b;
		if(myfind(a)==myfind(b)) cout<<"Y"<<endl;
		else cout<<"N"<<endl;
	}
	return 0;
}
