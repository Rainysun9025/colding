#include <stdio.h>
#include <string.h>
#define max 250
//高精度加法 
int main()
{
	char s1[max],s2[max];
	int len_1,len_2;
	scanf("%s",s1);
	scanf("%s",s2);
	len_1=strlen(s1);len_2=strlen(s2);
	int a[max]={0},b[max]={0};
	int ans[max+1]={0};
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
	int M=(len_1>len_2)?len_1:len_2;
	for(i=0;i<M;i++)
	{
		temp=a[i]+b[i]+ans[i];
		if(temp<10) ans[i]=temp;
		else
		{
			ans[i]=temp%10;
			ans[i+1]=temp/10;
		}
	}
	if(ans[M]!=0) printf("%d",ans[M]);
	for(i=M-1;i>=0;i--)
	{
		printf("%d",ans[i]);
	}
	return 0;
}

