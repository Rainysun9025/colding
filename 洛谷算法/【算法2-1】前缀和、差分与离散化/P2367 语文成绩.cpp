#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,p;
    cin>>n>>p;
    vector <int> arr(n+1);
    for(int i=1;i<=n;i++) cin>>arr[i];
    vector <int> dif(n+1);
    dif[1]=arr[1];
    for(int i=2;i<=n;i++) dif[i]=arr[i]-arr[i-1];
    while(p--)
    {
        int l,r;
        cin>>l>>r;
        int num;
        cin>>num;
        dif[l]+=num;
        if(r+1<=n) dif[r+1]-=num;
    }
    arr[1]=dif[1];
    for(int i=2;i<=n;i++)
    {
        arr[i]=dif[i]+arr[i-1];
    }
    sort(arr.begin()+1,arr.end());
    cout<<arr[1]<<endl;
    return 0;
}