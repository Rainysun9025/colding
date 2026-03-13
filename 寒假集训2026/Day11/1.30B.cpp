#include <stdio.h>
long long fast_exponentiation(long long a,long long b)
//¿ìËÙ¼ÆËã(a^b)modp 
{
	long long ans=1;
	while(b!=0)
	{
		if((b&1)==1)
		{
			ans=ans*a;
			ans=ans;
		}
		b=b>>1;
		a=(a*a);
	}
	return ans;
}
int main()
{
    long long B;
    scanf("%lld",&B);
    long long i;
    for(i=1;i<=100;i++)
    {
    	if(fast_exponentiation(i,i)==B)
    	{
    		printf("%d",i);
    		return 0;
		}
		if(fast_exponentiation(i,i)>B)
		{
			printf("-1");
			return 0;
		}
	}
    return 0;
}
