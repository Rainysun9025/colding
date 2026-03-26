#include <bits/stdc++.h>
using namespace std;
int n,m;
vector <pair<pair<int,int>,int> > arr;
int vis[100];
int ans=0;
void DFS(int cur,int sum)
{
     ans = max(ans, sum);
    for(int i=0;i<m;i++)
    {  
        if(arr[i].first.first==cur&&vis[arr[i].first.second]==0)
        {
            vis[arr[i].first.second]=1;
            DFS(arr[i].first.second,sum+arr[i].second);
            vis[arr[i].first.second]=0;
        }
        if(arr[i].first.second==cur&&vis[arr[i].first.first]==0)
        {
            vis[arr[i].first.first]=1;
            DFS(arr[i].first.first,sum+arr[i].second);
            vis[arr[i].first.first]=0;
        }

    }
    return;
}
int main()
{
    cin>>n>>m;
    int a,b,c;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        arr.push_back({{a,b},c});
    }
    for(int i=0;i<m;i++)
    {
        vis[arr[i].first.first]=1;
        DFS(arr[i].first.first,0);
        vis[arr[i].first.first]=0;
    }
    for(int i=0;i<m;i++)
    {
        vis[arr[i].first.second]=1;
        DFS(arr[i].first.second,0);
        vis[arr[i].first.second]=0;
    }
    cout<<ans<<endl;
    return 0;
}