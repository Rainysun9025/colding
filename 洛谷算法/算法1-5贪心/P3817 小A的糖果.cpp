#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,x;
    cin>>n>>x;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int sum=0;
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            if(arr[0]+arr[1]<=x) continue;
            else if(arr[0]+arr[1]>x)
            {
                int dis=(arr[0]+arr[1])-x;
                if(dis<=arr[1])
                {
                    sum+=dis;
                    arr[1]-=dis;
                }
                else if(dis>arr[1])
                {
                    sum+=arr[1];
                    dis-=arr[1];
                    arr[1]=0;
                    sum+=dis;
                    arr[0]-=dis;
                }
            }
            continue;
        }
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