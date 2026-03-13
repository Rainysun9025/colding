#include <stdio.h>
#include <stdlib.h>
int cmp(const void* a,const void* b)
{
    return (*(long long*)a-*(long long*)b);
}
int main(int argc, char *argv[])
{
  // 请在此输入您的代码
  long N,M;
  scanf("%lld %lld",&N,&M);
  long a[N];
  long i;
  for(i=0;i<N;i++)
  {
      scanf("%lld",&a[i]);
  }
  qsort(a,N,sizeof(long long),cmp);
  long long min;long long temp=0;
  min=a[M-1]*a[M-1]-a[0]*a[0];
  for(i=0;i+M-1<N;i++)
  {
      temp=a[i+M-1]*a[i+M-1]-a[i]*a[i];
      if(temp<min)
      {
          min=temp;
      }
  }
  printf("%lld",min);
  return 0;
}
