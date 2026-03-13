#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  // 请在此输入您的代码
  long long T;
  scanf("%lld",&T);
  long long i,u;
  double jin,yin,tong;
  long long K;
  long long ans_j,ans_y,ans_t;
  double a,b,c;
  for(i=1;i<=T;i++)
  {
    scanf("%lf %lf %lf %lld",&jin,&yin,&tong,&K);
    for(u=1;u<=K;u++)
    {
        a=(yin+tong)/2;a=(int)a;
        b=(jin+tong)/2;b=(int)b;
        c=(jin+yin)/2;c=(int)c;
        jin=a;
        yin=b;
        tong=c;
        if(jin==yin&&jin==tong&&yin==tong) break;
    }   
    ans_j=(int)jin;ans_t=(int)tong;ans_y=(int)yin;
    printf("%lld %lld %lld\n",ans_j,ans_y,ans_t);
  }
  return 0;
}
