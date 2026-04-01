#include <bits/stdc++.h>
using namespace std;
void gouzao(vector<vector<int>>& arr,vector<vector<int>>& prefix,int n)
{
    for(int i=1;i<=n;i++) //第一行
    {
        prefix[1][i]=prefix[1][i-1]+arr[1][i];
    }
    for(int i=1;i<=n;i++) //第一列
    {
        prefix[i][1]=prefix[i-1][1]+arr[i][1];
    }
    for(int i=2;i<=n;i++)
    {
        for(int u=2;u<=n;u++)
        {
            prefix[i][u]=prefix[i-1][u]+prefix[i][u-1]-prefix[i-1][u-1]+arr[i][u];
        }
    }
    return;
}
int solve(vector<vector<int>>& arr,vector<vector<int>>& prefix,int n)
{
    int cur=0;
    int maxsum=INT_MIN;
    //子矩阵右下角为x1,y1   1<=x1,y1<=n
    //子矩阵左上角为x2,y2   0<=x2<x1    0<=y2<y1
    int x1,y1,x2,y2;
    for(x1=1;x1<=n;x1++)
    {
        for(y1=1;y1<=n;y1++)
        {
            for(x2=0;x2<x1;x2++)
            {
                for(y2=0;y2<y1;y2++)
                {
                    int cur=prefix[x1][y1]-prefix[x1][y2]-prefix[x2][y1]+prefix[x2][y2];
                    if(cur>maxsum) maxsum=cur;
                }
            }
        }
    }
    return maxsum;
}
int main()
{
    int n;
    cin>>n;
    vector< vector <int> > arr( n+1,vector<int> (n+1,0) ) ;
    vector< vector <int> > prefix( n+1,vector<int> (n+1,0) ) ;
    for(int i=1;i<=n;i++)
    {
        for(int u=1;u<=n;u++)
        {
            cin>>arr[i][u];
        }
    }
    gouzao(arr,prefix,n);
    int ans=solve(arr,prefix,n);
    cout<<ans;
}