#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int N;
  int i;
  long long ans=0;
  long long a;
  scanf("%d" ,&N);
  for(i=1;i<=N;i++)
  {
    scanf("%lld",&a);
    if(a!=1) ans++; 
  }
  printf("%lld",ans);
  return 0;
}
