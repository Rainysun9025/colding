#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int arr[100005];
		int i;
		int k;
		scanf("%d",&k);
		for(i=1;i<=k;i++)
		{
			scanf("%d",&arr[i]);
		}
		int biao=0;
		int left=1;
		int right=2;
		while(arr[right]%arr[left]%2!=0)
		{
			right++;
			if(right==k+1)
			{
				left++;right=left+1;	
			}
			if(left==k)
			{
				biao=1;
				break;
			}
		}
		if(biao)
		{
			printf("-1\n");
			continue;
		}
	
		printf("%d %d\n",arr[left],arr[right]);
	}
	return 0;
}
