#include <stdio.h>
#include <string.h>
//arr[i]表示x=i直线能切分的三角形数量
//如果一个三角形的left和right长度差超过一
//那么就可以被
//   left+1  left+2  left+3.。。。。。。right-1给切分
//那么就要对arr[left+1]加一  arr[left+2]+1   .....arr[right-1]+1
//用差分   d[i]=a[i]-a[i-1]
//那么就是  d[left+1]+1
//if(right-1<=数组边界  d[right-1]+1;
//恢复i的时候，a[i]=d[i]+a[i-1]
//a[i-1]=d[i-1]+a[i-2]
//---->  a[i]=dp[i]+d[i-1]+...+d[1]
//用前缀和，qian[i]=d[i]+qian[i-1]
//a[i]=qian[i]
int dx[1000005];
		int qianx[1000005];
		int dy[1000005];
		int qiany[1000005];   
int min(int a,int b,int c)
{
	int m;
	m=(a<=b)?a:b;
	m=(m<=c)?m:c;
	return m;
}
int max(int a,int b,int c)
{
	int m;
	m=(a>=b)?a:b;
	m=(m>=c)?m:c;
	return m;
}
int main()
{
	int N;
	scanf("%d",&N);
	int i,u,l;
	int x1,y1;
	int x2,y2;
	int x3,y3;
	
	for(i=1;i<=N;i++)
	{
		scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);
		int left,right;
		left=min(x1,x2,x3);
		right=max(x1,x2,x3);
		if(left+1!=right)
		{
			//left+1  一直到   right-1
			 dx[left+1]++;
			 dx[right]--;
		}
		left=min(y1,y2,y3);
		right=max(y1,y2,y3);
		if(left+1!=right)
		{
			dy[left+1]++;
			dy[right]--;
		}
	}
	for(i=1;i<=1000000;i++)
	{
		qianx[i]=dx[i]+qianx[i-1];
		qiany[i]=dy[i]+qiany[i-1];
	}
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		char a,b;
		int c;
		while(1)
		{
			scanf("%c",&a);
			if(a=='\n') continue;
			if(a=='x'||a=='y') break;
		}
		scanf(" %c%d",&b,&c);
		int ans;
		if(a=='x')
		{
			ans=qianx[c];
			printf("%d\n",ans);
			continue;
		}
		else if(a=='y')
		{
			ans=qiany[c];
			printf("%d\n",ans);
			continue;
		}
	}
	return 0;
}
