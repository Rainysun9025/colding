#include <stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    int i;
    int p;
    while(scanf("%d",&p),p==0)
    {
        if(t==0)
        {
            return 0;
        }
        t--;
    }
    if(p==1)
    {
        if(t==0)
        {
            printf("%d",p);
            return 0;
        }
        printf("x^%d",t);
        t--;
    }
    else if(p==-1)
    {
        if(t==0)
        {
            printf("%d",p);
            return 0;
        }
        printf("-x^%d",t);
        t--;
    }
    else if(p==0)
    {
        if(t==0)
        {
            printf("%d",p);
            return 0;
        }
        t--;
    }
    else if(p>1)
    {
        if(t==0)
        {
            printf("%d",p);
            return 0;
        }
        printf("%dx^%d",p,t);
        t--;
    }
    else if(p<-1)
    {
        if(t==0)
        {
            printf("%d",p);
            return 0;
        }
        printf("%dx^%d",p,t);
        t--;
    }
    
    for(i=t;i>=2;i--)
    {
        scanf("%d",&p);
        if(p==1)
        {
            printf("+x^%d",i);
        }
        else if(p==-1)
        {
            printf("-x^%d",i);
        }
        else if(p==0)
        {
            continue;
        }
        else if(p<0)
        {
            printf("%dx^%d",p,i);
        }
        else if (p>0)
        {
            printf("+%dx^%d",p,i);
        }
    }
    scanf("%d",&p);
    if(p==1)
        {
            printf("+x");
        }
        else if(p==-1)
        {
            printf("-x",i);
        }

        else if(p<0)
        {
            printf("%dx",p);
        }
        else if (p>0)
        {
            printf("+%dx",p);
        }
    scanf("%d",&p);
    if(p>0)
    {
        printf("+%d",p);
    }
    if(p<0)
    {
        printf("%d",p);
    }
    
    return 0;
}
