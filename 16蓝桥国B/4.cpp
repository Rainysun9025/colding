#include <bits/stdc++.h>
using namespace std;
long long one[100005],zero[100005],inv[100005];
//第t个数； 有one[t]个1   zeor[t]个0   inv[t]个逆序对
#define MOD 1000000007
int main()
{
    long long T;
    cin>>T;
    one[1]=0;
    zero[1]=1;
    inv[1]=0;
    one[2]=1;
    zero[2]=0;
    inv[2]=0;
    while(T--)
    {
        long long n;
        cin>>n;
        if(inv[n]!=0)
        {
            cout<<inv[n]<<endl;
            continue;
        }
        for(long long i=3;i<=n;i++)
        {
            inv[i]=inv[i-1]+inv[i-2];
            inv[i]%=MOD;
            inv[i]+=one[i-2]*zero[i-1];
            inv[i]%=MOD;
            zero[i]=(zero[i-1]+zero[i-2])%MOD;
            one[i]=(one[i-1]+one[i-2])%MOD;
        }
        cout<<inv[n]<<endl;
    }
    return 0;
}