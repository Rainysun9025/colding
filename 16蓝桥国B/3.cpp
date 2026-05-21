#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long T;
    cin>>T;
    while(T--)
    {
        long long n,k;
        cin>>n>>k;
        if(k>=n)
        {
            k%=n;
            if(k==0)
            {
                cout<<"0"<<endl;
                continue;
            }
        }
        if(k==0)
        {
            cout<<"0"<<endl;
                continue;
        }
        //
        if((n-k)%2==0)
        {
            long long ans=(n-k)/2;
            cout<<ans<<endl;
            continue;
        }
        else if((n-k)%2!=0)
        {
            long long ans=0;
            ans+=(n-k-1)/2;
            ans+=1;
            if((n-1)%2==0)
            {
                ans+=(n-1)/2;
                cout<<ans<<endl;
                continue;
            }
            else if((n-1)%2!=0)
            {
                cout<<"-1"<<endl;
                continue;
            }
        }
    }
    return 0;
}