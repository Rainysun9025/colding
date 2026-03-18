#include <bits/stdc++.h>
using namespace std;
int Max;
int vol[11],jz[11];
void dfs(int bag,int cur,int sum_volume,int sum_jz)
{
    if(cur==11)
    {
        if(sum_jz>Max) Max=sum_jz;
        return;
    }
    dfs(bag,cur+1,sum_volume,sum_jz);
    if(sum_volume+vol[cur]<=bag)
    {
        dfs(bag,cur+1,sum_volume+vol[cur],sum_jz+jz[cur]);
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        Max=-1;
        int bag;
        cin>>bag;
        for(int i=1;i<=10;i++) cin>>vol[i];
        for(int i=1;i<=10;i++) cin>>jz[i];
        dfs(bag,1,0,0);
        cout<<Max<<endl;
    }
    return 0;
}