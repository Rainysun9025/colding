#include <bits/stdc++.h>
using namespace std;
int solve(int a,int b)//a>=b
{
    int temp;
    while(b!=0)
    {
        temp=a%b;
        a=b;
        b=temp;
    }
    return a;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        if(b>=a)
        {
            int temp=a;
            a=b;
            b=temp;
        }
        cout<<solve(a,b)<<endl;
    }
    return 0;
}