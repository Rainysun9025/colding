#include <bits/stdc++.h>
using namespace std;
int vis[10000008];
int jisuan_weishu(int i)
{
    int weishu=0;
    while(i!=0)
    {
        i=i/10;
        weishu++;
    }
    return weishu;
}
int main()
{
    int n;
    cin>>n;
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        if(i>=1&&i<=9)
        {
            if(i%2!=0)
            {
                ans++;
                vis[i]=1;
            }
            continue;
        }
        int cur_wei=jisuan_weishu(i);
        int u=i;
        int t;
        bool ji=true;
        bool if_keyi=true;
        for(int k=1;k<=cur_wei;k++)
        {
            t=u%10;
            u=u/10;
            if(ji==true)
            {
                if(t%2!=0)
                {
                    ji=false;
                    continue;
                }
                else if(t%2==0)
                {
                    if_keyi=false;
                    break;
                }
            }
            else if(ji==false)
            {
                if(t%2==0)
                {
                    ji=true;
                    continue;
                }
                else if(t%2!=0)
                {
                    if_keyi=false;
                    break;
                }
            }
        }
        if(if_keyi==true)
        {
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}