#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void* a,const void* b)
{
    int *pa=(int*)a;int *pb=(int *)b;
    if(pa[1]!=pb[1]) return pb[1]-pa[1];
    return pa[2]-pb[2];
}
int CMP(const void* a,const void* b)
{
	int* pa=(int *)a;
	int* pb=(int *)b;
	return pa[0]-pb[0];
} 
int main()
{
    int n;
    scanf("%d",&n);
    char name[n+1][20];
    int sol[n+1][3];//编号 多少个 标签出现次数的平均值
    for(int i=1;i<=n;i++)
        {
            sol[i][0]=i;
            sol[i][1]=0;
        }
    for(int i=1;i<=n;i++)
        {
            scanf("%s",name[i]);
            int ci;
            scanf("%d",&ci);
            sol[i][2]=ci;
            int vis[ci]; 
            for(int u=0;u<ci;u++)
                {
                    scanf("%d",&vis[u]);
                }
            qsort(vis,ci,sizeof(int),CMP);
            int num=1;
            int start=1;
            while(start<ci)
            {
            	if(vis[start]!=vis[start-1])
            	{
            		num++;start++;
				}
				else
				{
					start++;
				}
			}
			sol[i][1]=num;
        }
        qsort(sol+1,n,sizeof(int)*3,cmp);
        if(n==1)
        {
            printf("%s - -",name[1]);
            return 0;
        }
        if(n==2)
        {
            printf("%s %s -",name[sol[1][0]],name[sol[2][0]]);
            return 0;
        }
        printf("%s %s %s",name[sol[1][0]],name[sol[2][0]],name[sol[3][0]]);
    return 0;
}
