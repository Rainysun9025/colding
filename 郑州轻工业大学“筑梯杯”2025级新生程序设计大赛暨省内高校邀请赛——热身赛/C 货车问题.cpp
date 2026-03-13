#include <bits/stdc++.h>
using namespace std;
int main()
{
    int ans=0;
    int n,c;
    cin>>n>>c;
    int arr[n];
    int sum=0;
    int max=0;
    for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            sum+=arr[i];
            if(arr[i]>max) max=arr[i];
        }
    int left=max,right=sum,mid;
    while(left<=right)
        {
            int biao=1;
            int cnt=0;
            int cur=0;
            mid=(left+right)/2;
            for(int i=0;i<n;i++)
                {
                    if(cur+arr[i]>mid)
                    {
                        cur=0;
                        cnt++;
                        if(cnt>c)
                        {
                            biao=0;
                            break;
                        }
                    }
                    cur+=arr[i];
                    if(i==n-1) cnt++;
                    {
                        if(cnt>c) biao=0;
                    }
                }
            if(biao==0) left=mid+1;
            else
            {
                ans=mid;
                right=mid-1;
            }
        }
    cout<<ans;
    return 0;
}
