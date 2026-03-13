#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int x,y;
    int sum=0;
    int a[n],b[n],g[n],k[n];
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d %d %d %d",&a[i],&b[i],&g[i],&k[i]);
    }
    scanf("%d %d",&x,&y);
    for(i=0;i<n;i++)
    {
        if(x>=a[i]&&x<=a[i]+g[i]&&y>=b[i]&&y<=b[i]+k[i])
            sum=i+1;
    }
    if(sum>=1)
    {
        printf("%d",sum);
    }
    else
    {
        printf("-1");
    }
    return 0;
}
