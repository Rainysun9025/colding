#include <bits/stdc++.h>
using namespace std;
int main()
{
    deque<int> dq[14];
    vector<int> vis(14,0);//记录每一堆牌有几张正面
    vector<int> ans(14,0);
    for(int i=1;i<14;i++)
    {
        char a;
        int b;
        for(int u=1;u<=4;u++)
        {
            cin>>a;
            if(a=='0') b=10;
            else if(a=='A') b=1;
            else if(a=='J') b=11;
            else if(a=='Q') b=12;
            else if(a=='K') b=13;
            else if(a>='2'&&a<='9') b=a-'0';
            dq[i].push_back(b);
        }
    }
    int num=4;
    while(num!=0)
    {
        int cur,next;
        cur=dq[13].front();//第13堆抽出的牌
        dq[13].pop_front(); 
        while(cur!=13)
        {
            dq[cur].push_front(cur);//把牌放到上面
            vis[cur]++;
            next=dq[cur].back();//抽出最下面一张牌
            dq[cur].pop_back();//
            cur=next;
        }
        num--;
    }
    for(int i=1;i<=12;i++)
    {
        if(vis[i]>=4) vis[i]=4;
        for(int u=0;u<vis[i];u++)
        {
            int s=dq[i].front();
            dq[i].pop_front();
            ans[s]++;
        }
    }
    int answer=0;
    for(int i=1;i<=12;i++)
    {
        if(ans[i]==4) answer++;
    }
    cout<<answer;
    return 0;
}
