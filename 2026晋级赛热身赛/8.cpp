#include <stdio.h>
int sushu(long long n)
{
    long long i;
    if(n==1) return 0;
    if(n==2) return 1;    
    for(i=2;i*i<=n;i++)
        {
            if(n%i==0) return 0;
        }
    return 1;
}
int main()
{
    long long n;
    for(long long i=2;i<n;i++)
        {
            if(sushu(i)==0) continue;
            else
            {
                if(sushu(n-i)==0) continue;
                else
                {
                    printf("%d = %d + %d",n,i,n-i);
                    return 0;
                }
            }
        }
    return 0;
}
