#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int n,s,x;
		scanf("%d %d %d",&n,&s,&x);
		int i;
		int b;
		int sum=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&b);
			sum+=b;
		}
		if(sum==s)
		{
			printf("YES\n");
			continue;
		}
		if(sum>s)
		{
			printf("NO\n");
			continue;
		}
		if((s-sum)%x==0)
		{
			printf("YES\n");
			continue;
		}
		printf("NO\n");
	}
	return 0; 
}
