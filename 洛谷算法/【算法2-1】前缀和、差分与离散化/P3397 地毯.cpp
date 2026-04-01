#include <bits/stdc++.h>
using namespace std;
void change(vector<vector<int> >& dif,int n,int x1,int y1,int x2,int y2)
{
    dif[x1][y1]+=1;
    if(x2+1<=n) dif[x2+1][y1]-=1;
    if(y2+1<=n) dif[x1][y2+1]-=1;
    if(x2+1<=n&&y2+1<=n) dif[x2+1][y2+1]+=1;
    return;
}
void restoreFromDiff(vector<vector<int> >& dif,vector<vector<int> >& arr,int n)
{
    for(int i=1;i<=n;i++) arr[1][i]=dif[1][i]+arr[1][i-1];
    for(int i=1;i<=n;i++) arr[i][1]=dif[i][1]+arr[i-1][1];
    for(int i=2;i<=n;i++)
    {
        for(int u=2;u<=n;u++)
        {
            arr[i][u]=arr[i-1][u]+arr[i][u-1]-arr[i-1][u-1]+dif[i][u];
        }
    }
    return;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector < vector <int> > arr(n+1,vector <int> (n+1,0));
    vector < vector <int> > dif(n+1,vector <int> (n+1,0));
    while(m--)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        change(dif,n,x1,y1,x2,y2);
    }
    restoreFromDiff(dif,arr,n);
    for(int i=1;i<=n;i++)
    {
        for(int u=1;u<=n;u++)
        {
            cout<<arr[i][u]<<" ";
        }
        cout<<endl;
    }
    return 0;
}