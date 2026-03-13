#include <bits/stdc++.h>
using namespace std;
int main()
{
	string a;
	cin>>a;
	char b;
	stack<int> st;
	int i=0;
	int num;
	while(i<a.length())
	{
		num=0;
		b=a[i];
		if(isdigit(b))
		{
			num=b-'0';
			i++;
			while(i<a.length()&&isdigit(a[i]))
			{
				num=num*10+a[i]-'0';
				i++;
			}
			st.push(num);
		}
		else if(b=='.') i++;
		else if(b=='+'||b=='-'||b=='*'||b=='/')
		{
			int left,right;
			right=st.top();st.pop();
			left=st.top();st.pop();
			if(b=='+') num=left+right;
			if(b=='-') num=left-right;
			if(b=='*') num=left*right;
			if(b=='/') num=left/right;
			st.push(num);
			i++;
		}
		else if(b=='@') break;
	}
	cout<<st.top();
	return 0;
 } 
