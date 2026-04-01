#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector <int> arr(n+1);
    for(int i=1;i<=n;i++) cin>>arr[i];
    vector <int> dif(n+1);
    dif[1]=arr[1];
    for(int i=2;i<=n;i++) dif[i]=arr[i]-arr[i-1];
    long long up=0,low=0;
    for(int i=2;i<=n;i++)
    {
        if(dif[i]<0) low-=dif[i];
        else if(dif[i]>0) up+=dif[i];
    }
    // 最少步骤为 min(low,up)+|low-up|
    //即max(low,up);
    cout<<max(low,up)<<endl;
    cout<<abs(low-up)+1<<endl;
    return 0;

}