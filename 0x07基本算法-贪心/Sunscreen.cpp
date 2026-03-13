#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 2505
int temporary[MAX][4];
int cmp(const void* a,const void *b)
{
    return (*(int*)a-*(int*)b);
}
int CMP(const void* a,const void *b)
{
    const int* A=(const int*)a;
    const int* B=(const int*)b;
    A++;B++;
    return *A-*B;
}
int main()
{
    int num_cow,num_spf;
    scanf("%d %d",&num_cow,&num_spf);
    int i,u,l;
    int cow[num_cow][4];
    int spf[num_spf][2];
    int cur=0;
    int ans=0;
    for(i=0;i<num_cow;i++)
    {
        scanf("%d %d",&cow[i][0],&cow[i][1]);
        cow[i][3]=0;
    }
    qsort(cow,num_cow,sizeof(int)*4,cmp);
    for(i=0;i<num_cow;i++)
    {
        cow[i][2]=i;
    }
    for(i=0;i<num_spf;i++)
    {
        scanf("%d %d",&spf[i][0],&spf[i][1]);
    }
    qsort(spf,num_spf,sizeof(int)*2,cmp);
    for(i=0;i<num_spf;i++)
    {
        memset(temporary,0,sizeof(int)*MAX);
        u=0;
        l=0;
        while(u<num_cow&&cow[u][0]<=spf[i][0])
        {
            temporary[u][0]=cow[u][0];
            temporary[u][1]=cow[u][1];
            temporary[u][2]=cow[u][2];
            temporary[u][3]=cow[u][3];
            u++;
        }
        qsort(temporary,u,sizeof(int)*4,CMP);
        while(spf[i][1]>0&&l<u)
        {
            if(temporary[l][1]>=spf[i][0]&&temporary[l][3]==0)
            {
                ans++;
                spf[i][1]--;
                temporary[l][3]=1;
                cow[temporary[l][2]][3]=1;
            }
            l++;
        }
    }
    printf("%d",ans);
    return 0;
}
