#include <stdio.h>
long long fast_exponentiation(long long a,long long b,long long p)
//¿ìËÙ¼ÆËã(a^b)modp 
{
    if(p==1)
    {
        return 0;
    }
	long long ans=1;
	while(b!=0)
	{
		if((b&1)==1)
		{
			ans=ans*a;
			ans=ans%p;
		}
		b=b>>1;
		a=(a*a)%p;
	}
	return ans;
}
int main()
{
    long long a,b,p;
    scanf("%lld %lld %lld",&a,&b,&p);
    long long ans=fast_exponentiation(a,b,p);
    printf("%lld",ans);
    return 0;
}
