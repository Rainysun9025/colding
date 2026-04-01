#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n+1];
    int prefix[n+1];
    prefix[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        prefix[i]=prefix[i-1]+arr[i];
    }
    int m;
    cin>>m;
    while(m--)
    {
        int l,r;
        cin>>l>>r;
        cout<<prefix[r]-prefix[l-1]<<endl;
    }
    return 0;
}