#include <stdio.h>
#include <string.h>
#define max 250
//高精度减法 
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
	int fuhao=1;
	if(len_1>len_2) fuhao=1;
	else
	{
	    if(len_1==len_2)
	    {
	        if(strcmp(s1,s2)<0)//s1-s2<0
	        {
	            fuhao=0;
	            char s3[max];
	            strcpy(s3,s1);strcpy(s1,s2);strcpy(s2,s3);
	        }
	    }
	    else//len_1<len_2
	    {
	        fuhao=0;
	        char s3[max];
	        strcpy(s3,s1);strcpy(s1,s2);strcpy(s2,s3);
	        len_1^=len_2;
	        len_2^=len_1;
	        len_1^=len_2;
	    }
	}
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
	    if(a[i]>=b[i])
	    {
	        ans[i]=a[i]-b[i];
	    }
	    else
	    {
	        a[i]+=10;a[i+1]-=1;
	        ans[i]=a[i]-b[i];
	    }
	}
	int biao=-1;
	for(i=M-1;i>=0;i--)
	{
	    if(ans[i]!=0)
	    {
	        biao=i;
	        break;
	    }
	}
	if(biao==-1)
	{
	    printf("0");
	    return 0;
	}
	if(fuhao==0)
	{
	    printf("-");
	}
	for(i=biao;i>=0;i--)
	{
	    printf("%d",ans[i]);
	}
	return 0;
}
