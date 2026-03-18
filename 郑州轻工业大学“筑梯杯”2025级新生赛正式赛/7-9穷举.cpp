#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int bag;
        cin>>bag;
        int mask=0;
        int v[11],w[11];
        for(int i=1;i<=10;i++) cin>>v[i];
        for(int i=1;i<=10;i++) cin>>w[i];
        int sum_volume,sum_jiazhi;
        int max=-1;
        for(mask=0;mask<(1<<10);mask++)
        {
            sum_jiazhi=0;sum_volume=0;
            int temp=mask;
            for(int u=1;u<=10;u++)
            {
                if(temp&1)
                {
                    sum_volume+=v[u];
                    sum_jiazhi+=w[u];
                }
                temp=temp>>1;
            }
            if(sum_volume>bag) continue;
            if(sum_jiazhi>max) max=sum_jiazhi;
        }
        cout<<max<<endl;
    }
    return 0;
}