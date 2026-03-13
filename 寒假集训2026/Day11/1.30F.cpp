#include <stdio.h>
#include <string.h>
int main()
{
	char arr[2*100005];
	scanf("%s",arr);
	int used[2*100005][2];
	int i,u,l=0;
	int len1=strlen(arr);
	for(i=0;i<len1;i++)
	{
		if(arr[i]=='A'&&arr[i+1]=='B'&&arr[i+2]=='C')
		{
			used[l][0]=i;used[l][1]=i+2;
			l++;
			i=i+2;
			continue;
		}	
	}
	for(i=0;i<l;l++)
	{
		int left,right;
		while(1)
		{
			left=used[i][0];
			right=used[i][1];
			if(left-1>=0&&right+2<len1)
			{
				if(arr[left-1]=='A'&&arr[right+1]=='B'&&arr[right+2]=='C')
				{
					used[i][0]==left-1;
					used[i][1]=right+2;
					continue;
				}
			}
			if(left-2>=0&&right+1<len1)
			{
				if(arr[left-2]=='A'&&arr[left-1]=='B'&&arr[right+1]=='C')
				{
					used[i][0]=left-2;
					used[i][1]=right+1;
					continue;
				}
			}
			break;
		}
	}
	used[l][0]=1000000;
	u=0;
	for(i=0;i<len1;i++)
	{
		if(i<used[u][0]) printf("%c",arr[i]);
		else if(i>=used[u][0]&&i<=used[u][1])
		{
			i=used[u][1];
			u++;	
			continue;
		}
	}
	return 0;
}
