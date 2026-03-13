#include <stdio.h>
#include <string.h>
long long arr[100000],temp[100000];
int N,F;
int MY(long long mid,long long *prefix,long long *mini)
{
    
    int i,u,l;
    prefix[0]=0;
    mini[0]=prefix[0];
    for(i=0;i<N;i++)
    {
        temp[i]-=mid;
    }
    for(i=1;i<=N;i++)
    {
        prefix[i]=prefix[i-1]+temp[i-1];
    }
    for(i=1;i<=N-F;i++)
    {
        mini[i]=(mini[i-1]<=prefix[i])?mini[i-1]:prefix[i];
    }
    for(i=F;i<=N;i++)
    {
        if(prefix[i]-mini[i-F]>=0) return 1;
    }
    return 0;
}

int main()
{
    int ans=0;
    scanf("%d %d",&N,&F);
    long long prefix[N+1];
    long long mini[N-F+2];
    int i,u,l;
    long long left=2000005,right=0;
    for(i=0;i<N;i++)
    {
        scanf("%lld",&arr[i]);
        arr[i]=arr[i]*1000;
        if(arr[i]<left) left=arr[i];
        if(arr[i]>right) right=arr[i];
    }
    long long mid=(left+right)/2;
    while(left<=right)
    {
        memcpy(temp,arr,N*sizeof(long long));
        if(MY(mid,prefix,mini)==1)
        {
            left=mid+1;
            if(ans<mid) ans=mid;
        }
        else
        {
            right=mid-1;
        }
        mid=(left+right)/2;
    }
    printf("%lld",ans);
    return 0;
}
