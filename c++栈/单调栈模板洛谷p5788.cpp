#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n; 
	int arr[n+1];
	int i,u,l;
	int ans[n+1];
	for(i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	stack<int> st;
	for(i=n;i>=1;i--)
	{
		while(!st.empty()&&arr[st.top()]<=arr[i]) st.pop();
		if(st.empty()) ans[i]=0;
		else ans[i]=st.top();
		st.push(i);
	}
	for(i=1;i<=n;i++) cout<<ans[i]<<" ";
	return 0;
}
