#include <bits/stdc++.h>
using namespace std;
int main()
{
	int x;
	cin>>x;
	int wei=1;
	int cur=1;
	bool start=false;
	if(1%x==0)
	{
		cout<<"1 1";
		return 0;
	}
	while(cur%x!=0)
	{
		if(start==false)
		{
			if(cur/x!=0)
			{
				start=true;
			}
		}
		if(start==true)
		{
			int temp=cur/x;
			cout<<temp;
		}
		cur=cur%x*10+1;
		wei++;
	}
	cout<<cur/x; 
	cout<<" "<<wei;
	return 0;
}
