#include <stdio.h>
int main()
{
    int n;
    int i;
    int k;
    long long sum=0;
    while(scanf("%d",&n),n!=0)
    {
        sum=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&k);
            sum=sum^k;
        }
        printf("%lld\n",sum);
    }
    
    return 0;
}
