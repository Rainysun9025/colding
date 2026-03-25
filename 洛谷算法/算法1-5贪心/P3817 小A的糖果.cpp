#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,x;
    cin>>n>>x;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    long long sum=0;
    for(int i=1;i<n;i++)
    {
        if(arr[i]+arr[i-1]>x)
        {
            int dis=(arr[i]+arr[i-1])-x;
            if(dis<=arr[i])
            {
                sum+=dis;
                arr[i]-=dis;
            }
            else if(dis>arr[i])
            {
                sum+=dis;
                dis-=arr[i];
                arr[i]=0;
                arr[i-1]-=dis;
            }
        }
        else if(arr[i]+arr[i-1]<=x) continue;
    }
    cout<<sum<<endl;
    return 0;
}