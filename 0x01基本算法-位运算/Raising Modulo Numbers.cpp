#include <stdio.h>
long long fast(long long a,long long b,long long p)
{
    long long ans=1;
    if(p==1)
    {
        return 0;
    }
    while(b!=0)
    {
        if(b&1==1)
        {
            ans=ans*a;
            ans=ans%p;
        }
        a=a*a%p;
        b=b>>1;
    }
    return ans;
}
int main()
{
    long long T;
    long long i,u;
    long long a,b,p;
    long long sum=0;
    long long n;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        sum=0;
        scanf("%lld",&p);
        scanf("%lld",&n);
        for(u=1;u<=n;u++)
        {
            scanf("%lld %lld",&a,&b);
            sum=sum+fast(a,b,p);
            sum=sum%p;
        }
        printf("%lld\n",sum);   
    }
    return 0;
}
