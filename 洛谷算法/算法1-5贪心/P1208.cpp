#include <bits/stdc++.h>
using namespace std;
int cmp(const void* a,const void* b)
{
    long long *pa=(long long *)a;
    long long *pb=(long long *)b;
    return pa[0]-pb[0];
}
int main()
{
    long long n,m;
    cin>>n>>m;
    long long arr[m][2]; 
    for(int i=0;i<m;i++)
    {
        cin>>arr[i][0];
        cin>>arr[i][1];
    }
    qsort(arr,m,sizeof(long long)*2,cmp);
    long long sum=0;
    for(long long i=0;i<m;i++)
    {
        if(n>=arr[i][1])
        {
            n-=arr[i][1];
            sum+=arr[i][1]*arr[i][0];
        }
        else if(n<arr[i][1])
        {
            sum+=arr[i][0]*n;
            break;
        }
    }
    cout<<sum<<endl;
    return 0;
}