#include <stdlib.h>
#include <stdio.h>
long long ans=0;
void merge_sort(long long* a,long long p,long long q);
void merge(long long *a,long long p,long long mid,long long q);
int main()
{
    long long n;
    scanf("%lld",&n);
    long long a[n+1];
    long long i;
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    merge_sort(a,1,n);
    printf("%lld",ans);
    return 0;
}
void merge_sort(long long* a,long long p,long long q)
{
    if(p>=q)//数组中只能有一个元素最终
    {
        return;
    }
    long long mid;
    mid=(p+q)/2;
    merge_sort(a,p,mid);
    merge_sort(a,mid+1,q);
    merge(a,p,mid,q);
    return;
}
void merge(long long *a,long long p,long long mid,long long q)
{
    long long len_1=mid-p+1;
    long long len_2=q-mid;
    long long *left=(long long*)malloc(sizeof(long long)*len_1);
    long long *right=(long long*)malloc(sizeof(long long)*len_2);
    long long t=0;
    long long i;
    for(i=p;i<=mid;i++)
    {
        left[t]=a[i];
        t++;
    }
    t=0;
    for(i=mid+1;i<=q;i++)
    {
        right[t]=a[i];
        t++;
    }
    i=p;
    long long *left_end=&left[len_1];
    long long *right_end=&right[len_2];
    while(left!=left_end&&right!=right_end)
    {
        if(*left<=*right)
        {
            a[i]=*left;
            left++;
        }
        else if(*left>*right)
        {
            a[i]=*right;
            right++;
            ans+=(left_end-left);
        }
        i++;
    }
    while(left<left_end)
    {
        a[i++]=*left++;
    }
    while(right<right_end)
    {
        a[i++]=*right++;
    }
    return;
}
