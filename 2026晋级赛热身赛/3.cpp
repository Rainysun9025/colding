#include <stdio.h>
double x(int p)
{
    double ans=1;
    for(int i=1;i<=p;i++)
        {
            ans=ans*(1.0/i);
        }
    return ans;
}
int main()
{
    int n;
    scanf("%d",&n);
    int i;
    double sum=1;
    double pre=1;
    
    for(i=1;i<=n;i++)
        {
            double cur;
            cur=x(i);
            sum=sum+cur;
        }
    printf("%.8lf\n",sum);
    return 0;
}
