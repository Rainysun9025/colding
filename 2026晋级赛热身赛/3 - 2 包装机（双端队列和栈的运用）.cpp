#include <bits/stdc++.h>
using namespace std;
int main()
{
	deque <char> de;
	int n,m,s;//轨道的条数、每条轨道初始放置的物品数量、以及筐的最大容量
	cin>>n>>m>>s;
	stack<char> st[n];
	for(int i=0;i<n;i++)
	{
		char a[m];
		for(int u=0;u<m;u++) cin>>a[u];
		for(int u=m-1;u>=0;u--) st[i].push(a[u]);
	}
	while(1)
	{
		int a;
		cin>>a;
		if(a==-1) break;
		if(a==0)
		{
			if(de.empty()) continue; 
			cout<<de.back();
			de.pop_back();
			continue;
		}
		if(st[a-1].empty()) continue;
		if(de.size()==s)
		{
			cout<<de.back();
			de.pop_back();
		}
		char temp=st[a-1].top();
		st[a-1].pop();
		de.push_back(temp);
	}
	return 0;
}
  
