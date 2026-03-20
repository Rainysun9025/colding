#include <bits/stdc++.h>
using namespace std;
int ci=1;
void solve(int num,char a,char b,char c)//起始 辅助 终止
{
    if(num==1)
    {
        printf("%d: %c -> %c\n",ci,a,c);
        return;
    }
    else
    {
        solve(num-1,a,c,b);
        printf("%d: %c -> %c\n",ci,a,c);
        ci++;
        solve(num-1,b,a,c);
    }
    return;
}
int main()
{
    int num;
    cin>>num;
    char a,b,c;
    cin>>a>>b>>c;
    solve(num,a,b,c);
    return 0;
}