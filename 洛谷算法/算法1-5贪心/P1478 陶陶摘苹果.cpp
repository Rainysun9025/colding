#include <bits/stdc++.h>
using namespace std;
int cmp(const void *a,const void *b)
{
    int *pa=(int *)a;
    int *pb=(int *)b;
    return *pa-*pb;
}
int CMP(const void *a,const void *b)
{
    int *pa=(int *)a;
    int *pb=(int *)b;
    return pa[1]-pb[1];
}
int main()
{
    int n,s;
    int a,b;
    cin>>n>>s;
    cin>>a>>b;
    int arr[n][2];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i][0]>>arr[i][1];
    }
    qsort(arr,n,sizeof(int)*2,cmp);
    int height=a+b;
    int after[n][2];
    int k=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i][0]>height) break;
        after[k][0]=arr[i][0];
        after[k][1]=arr[i][1];
        k++;
    }
    qsort(after,k,sizeof(int)*2,CMP);
    int ans=0;
    for(int i=0;i<k;i++)
    {
        if(s>=after[i][1])
        {
            s-=after[i][1];
            ans++;
        }
        else break;
    }
    cout<<ans<<endl;
    return 0;
}