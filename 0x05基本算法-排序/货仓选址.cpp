#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a,const void* b)
{
    return (*(int*)a-*(int *)b);
}
int main()
{
    int n;
    int base=0;
    long long sum=0;
    scanf("%d",&n);
    int arr[n];
    int i,u;
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    qsort(arr,n,sizeof(int),cmp);
    if(n%2==0)
    {
        u=n/2;u=u-1;
        base=arr[u];
        for(i=0;i<n;i++)
        {
            if(i<=u) sum=sum+base-arr[i];
            else if(i>u) sum=sum+arr[i]-base;
        }
    }
    else
    {
        u=(n+1)/2;u=u-1;
        base=arr[u];
        for(i=0;i<n;i++)
        {
            if(i<=u) sum=sum+base-arr[i];
            else if(i>u) sum=sum+arr[i]-base;
        }
    }
    printf("%lld",sum);
    return 0;
}
