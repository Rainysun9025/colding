#include <stdio.h>

int main()
{
    long long n,q;
    scanf("%lld %lld",&n,&q);
    getchar();
    long long a[n+1];
    long long b[n+1];
    long long i;
    scanf("%lld",&a[1]);
    b[1]=a[1];
    for(i=2;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        b[i]=a[i]-a[i-1];
    }
    getchar();
    long long l,r,d;
    long long u;
    for(i=1;i<=q;i++)
    {
        scanf("%lld %lld %lld",&l,&r,&d);
        getchar();
        b[l]=b[l]+d;b[r+1]=b[r+1]-d;
    }
    printf("%lld",b[1]);
    long long k=b[1];
    for(i=2;i<=n;i++)
    {
        k=k+b[i];
        printf(" %lld",k);
    }
    return 0;
    
}
