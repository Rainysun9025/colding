#include <bits/stdc++.h>
using namespace std;
int cmp(const void *a,const void *b)
{
    double *pa=(double *)a;
    double *pb=(double *)b;
    if(*pa<*pb) return 1;
    else if(*pa>*pb) return -1;
    return 0;
}
int main()
{
    int n,t;
    cin>>n>>t;
    int m[n],v[n];
    for(int i=0;i<n;i++) cin>>m[i]>>v[i];
    double danwei[n][2];
    for(int i=0;i<n;i++)
    {
        danwei[i][0]=v[i]*1.0/m[i];
        danwei[i][1]=m[i];
    }
    qsort(danwei,n,sizeof(double)*2,cmp);
    double sm=0;
    for(int i=0;i<n;i++)
    {
        if(t==0) break;
        if(t>=danwei[i][1])
        {
            sm+=danwei[i][0]*danwei[i][1];
            t-=danwei[i][1];
        }
        else if(t<danwei[i][1])
        {
            sm+=danwei[i][0]*t;
            t=0;
        }
    }
    printf("%.2lf",sm);
    return 0;
}