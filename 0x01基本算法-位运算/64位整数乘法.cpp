#include <stdio.h>
#include <string.h>
#include <math.h>
#define max 250
//高精度乘法
int main()
{
	char s1[max],s2[max];
	long long mod;
	int len_1,len_2;
	scanf("%s",s1);
	scanf("%s",s2);
	scanf("%lld",&mod);
	len_1=strlen(s1);len_2=strlen(s2);
	int a[max]={0},b[max]={0};
	int ans[2*max+10]={0};
	int i=0;
	while(len_1-1-i!=-1)
	{
		a[i]=s1[len_1-1-i]-'0';
		i++;
	}
	i=0;
	while(len_2-1-i!=-1)
	{
		b[i]=s2[len_2-1-i]-'0';
		i++;
	}
	int temp;
	int p,q;
	for(p=0;p<len_1;p++)
	{
	    for(q=0;q<len_2;q++)
	    {
	        temp=a[p]*b[q]+ans[p+q];
	        if(temp<10)
	        {
	            ans[p+q]=temp;
	        }
	        else
	        {
	            ans[p+q]=temp%10;
	            ans[p+q+1]+=temp/10;
	        }
	    }
	}
	int M;
	for(i=2*max+9;i>=0;i--)
	{
	    if(ans[i]!=0)
	    {
	        M=i;
	        break;
	    }
	}
	long long sum=0;
	long long k;
	for(i=M;i>=0;i--)
	{
	    sum=(sum*10+ans[i])%mod;
	}
	printf("%lld",sum);
	return 0;
}
