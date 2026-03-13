#include<bits/stdc++.h>
using namespace std;
int main()
{
	list<int> L;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		L.push_back(i);
	}
	list<int>::iterator it=L.begin();
	while(L.size()>1)
	{
		for(int i=1;i<m;i++)
		{
			it++;
			if(it==L.end()) it=L.begin();
		}
		cout<<*it<<" ";
		auto next=++it;
		if(next==L.end()) next=L.begin();
		L.erase(--it);
		it=next;
	}
	cout<<L.front(); 
	return 0;
}
