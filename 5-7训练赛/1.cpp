#include <bits/stdc++.h>
using namespace std;
bool R(int* arr,int *t,int x,int dis)
{
    int u,p;
    u=x+1;
    p=1;
    for(int i=0;i<dis;i++)
    {
        if(arr[u++]!=t[p++]) return false;
    }
    return true;
}

bool L(int* arr,int *t,int x,int dis)
{
    int u,p;
    u=x-1;
    p=1;
    for(int i=0;i<dis;i++)
    {
        if(arr[u--]!=t[p++]) return false;
    }
    return true;
}
int main()
{
    int n,x,y;
    cin>>n>>x>>y;
    int arr[n+1];
    for(int i=1;i<=n;i++) cin>>arr[i];
    int m;
    cin>>m;
    int t[m+1];
    for(int i=1;i<=m;i++) cin>>t[i];
    if(x<y){
        if(x-m<1){
            cout<<"Right";
            return 0;
        }
        bool ans=R(arr,t,x,m);
        if(ans==false){
            cout<<"Wrong";
            return 0;
        }
        ans=L(arr,t,x,m);
        if(ans==false){
            cout<<"Right";
            return 0;
        }
        cout<<"Unsure";
        return 0;
    }
    else if(x>y){
        if(x+m>n){
            cout<<"Right";
            return 0;
        }
        bool ans=L(arr,t,x,m);
        if(ans==false){
            cout<<"Wrong";
            return 0;
        }
        ans=R(arr,t,x,m);
        if(ans==false){
            cout<<"Right";
            return 0;
        }
        cout<<"Unsure";
            return 0;
    }
    return 0;
}