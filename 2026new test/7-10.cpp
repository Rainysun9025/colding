#include <bits/stdc++.h>
using namespace std;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int main()
{
    int n,m;
    cin>>n>>m;
    char arr[n][n+5];
    int vis[n][n];
    for(int i=0;i<n;i++) scanf("%s",arr[i]);
    deque <pair<int,int>> de;
    int day[m+1];
    int sum=0;
    memset(day,0,sizeof(int)*(m+1));
    for(int i=0;i<n;i++)
    {
        for(int u=0;u<n;u++)
        {
            if(arr[i][u]=='@')
            {
                day[1]++;
                sum++;
                de.push_back({i,u});
                vis[i][u]=1;
                continue;
            }
            vis[i][u]=0;
        }
    }
    int cur_day=1;
    int cur_person=0;
    while(!de.empty())
    {
        if(cur_person==day[cur_day])
        {
            cur_day++;
            cur_person=0;
        }
        if(cur_day==m)
        {
            break;
        }
        int x,y;
        x=de.front().first;
        y=de.front().second;
        de.pop_front();
        int nex,ney;
        for(int u=0;u<4;u++)
        {
            nex=x+dx[u];
            ney=y+dy[u];
            if(nex<0||nex>=n||ney<0||ney>=n) continue;
            if(vis[nex][ney]==1) continue;
            if(arr[nex][ney]!='.') continue;
            vis[nex][ney]=1;
            day[cur_day+1]++;
            de.push_back({nex,ney});
            sum++;
        }
        cur_person++;
    }
    cout<<sum<<endl;
    return 0;
}