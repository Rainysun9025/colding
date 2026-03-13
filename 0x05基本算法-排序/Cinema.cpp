#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int many[600005];


int unique[600005];


int cmp(const void* a,const void* b)
{
    return (*(int*)a-*(int*)b);
}


int search(int n,int *si,int u,int *unique)//查找编号为n的语言的使用人数
//u代表总共出现过u种语言
//unique[k] 代表一种语言
//si[k] 代表编号为unique[k]的 语言的使用人数
{
    int left=0,right=u-1;
    int mid=(left+right)/2;
    while(left<=right)
    {
        if(n==unique[mid]) return si[mid];//注意n是编号，unique[mid]是编号 
        else if(n<unique[mid])
        {
            right=mid-1;
            mid=(left+right)/2;
        }
        else if(n>unique[mid])
        {
            left=mid+1;
            mid=(left+right)/2;
        }
    }
    return 0;
}



int main()
{
    int n,m;
    scanf("%d",&n);
    int science[n];
    int i,u,l;
    for(i=0;i<n;i++)
    {
        scanf("%d",&science[i]);
    }
    qsort(science,n,sizeof(int),cmp);
    scanf("%d",&m);
    int watch[m],listen[m];
    for(i=0;i<m;i++)
    {
        scanf("%d",&watch[i]);
    }for(i=0;i<m;i++)
    {
        scanf("%d",&listen[i]);
    }
    memcpy(many,science,n*sizeof(int));//memcpy第三个参数是元素个数*sizeof 
    memcpy(many+n,watch,m*sizeof(int));
    memcpy(many+n+m,listen,m*sizeof(int));
    i=1;u=1;
    //u代表总共出现过u种语言 
    unique[0]=many[0];
    while(1)
    {
        if(i==n+2*m)
        {
            break;
        }
        if(many[i]==many[i-1])
        {
            i++;continue;
        }
        else
        {
            unique[u]=many[i];
            u++;i++;continue;
        }
    }
    //unique[0]  unique[1]  unique[2]  .....  unique[u-1]
    //unique代表一种语言
    i=0;l=0;
    int si[u];//代表编号为unique[u]的语言的使用人数
    memset(si,0,u*sizeof(int));
    while(1)
    {
        if(i==n) break;
        if(science[i]==unique[l])
        {
            si[l]++;i++;//该科学家使用的就是unique[l]的语言
			//i++代表处理下一名科学家 
        }
        else if(science[i]>unique[l])//该科学家使用的语言编号大于unique[l]
 
        {
            while(science[i]>unique[l])
            {
                l++;
            }
        }
        else if(science[i]<unique[l])
        {
            while(science[i]<unique[l])
            {
                i++;
            }
        }
    }
    int best_biao=0;
    int best_watchnum;
    int best_listennum;
    i=0;
    while(unique[i]!=watch[0])
    {
        i++;
    }//用遍历的方法找到第一部电影watch语言使用人数 
    best_watchnum=si[i];
    i=0;
    while(unique[i]!=listen[0])
    {
        i++;
    }//用遍历的方法找到第一部电影listen语言使用人数 
    best_listennum=si[i];
    int cur=0;
    for(i=1;i<m;i++)
    {
        cur=search(watch[i],si,u,unique);//用函数的方法找到第i+1部电影的watch语言使用人数 
        if(cur<best_watchnum) continue;//先比较watch语言，小于直接去看下一部电影 
        else if(cur>best_watchnum)//大于直接替换 
        {
            best_biao=i;//替换编号 
            best_watchnum=cur;//替换watch人数 
            best_listennum=search(listen[i],si,u,unique);//替换listen人数 
        }
        else if(cur==best_watchnum)//在watch人数相同下比较listen人数 
        {
            cur=search(listen[i],si,u,unique);//用函数的方法找到第i+1部电影的listen语言使用人数 
            if(cur>best_listennum)
            {
                best_biao=i;
                best_watchnum=search(watch[i],si,u,unique);
                best_listennum=cur;
            }
        }
    }
    printf("%d",best_biao+1);//注意索引和电影标号差1 
    return 0;
}
