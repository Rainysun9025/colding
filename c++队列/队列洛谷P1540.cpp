#include <bits/stdc++.h>
using namespace std;
int Hash[1500]={0};
int main()
{
	int m,n;
	queue<int> L;
	int ans=0;
	cin>>m>>n;
	int a;
	while(n--)
	{
		cin>>a;
		if(Hash[a]==0)
		{
			ans++;
			Hash[a]=1;
			L.push(a);
		}
		while(L.size()>m)
		{
			Hash[L.front()]=0;
			L.pop();
		}
	}
	cout<<ans;
	return 0;
}
