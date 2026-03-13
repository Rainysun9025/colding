#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int num_contest,num_audience;
	scanf("%d %d",&num_contest,&num_audience);
	int pre_au[num_audience+1][2][num_contest+1];
	int NUM[num_audience+1];
	int real[num_contest+1];
	memset(real,0,sizeof(real));
	int which_contest[num_audience+1][2]; 
	int i;
	int a,b,c,d;
	for(i=1;i<=num_audience;i++)
	{
		scanf("%d %d %d %d",&a,&b,&c,&d);
		pre_au[i][0][a]=b;
		pre_au[i][1][c]=d;
		which_contest[i][0]=a;
		which_contest[i][1]=c;
		NUM[i]=1;
	}
	int num=1;
	for(i=1;i<=num_audience;i++)
	{
		if(i==0)
		{
			printf("None");
			return 0;
		}
		if(real[which_contest[i][NUM[i]]]==0)//第i个观众做的第NUM[i]次预测指向的运动员 
		{
			real[which_contest[i][NUM[i]]]=pre_au[i][NUM[i]][which_contest[i][NUM[i]]];
			continue;
		}
		else
		{
			NUM[i]++;
			if(real[which_contest[i][NUM[i]]]==0)
			{
				real[which_contest[i][NUM[i]]]=pre_au[i][NUM[i]][which_contest[i][NUM[i]]];
			}
			else
			{
				i--;
				while(1)
				{
					if(i==0)
					{
						printf("None");
						return 0;
					}
					if(NUM[i]==1)
					{
						real[which_contest[i][NUM[i]]]=0;
						NUM[i]++;
						if(real[which_contest[i][NUM[i]]]==0)
						{
							real[which_contest[i][NUM[i]]]=pre_au[i][NUM[i]][which_contest[i][NUM[i]]];
							break;
						}
						else
						{
							NUM[i]=1;
							i--;
							continue;
						}
					}
					else if(NUM[i]==2)
					{
						real[which_contest[i][NUM[i]]]=0;
						NUM[i]=1;
						i--;
						continue;
					}
				}
			}
		}
	}
	for(i=1;i<=num_contest;i++)
	{
	    printf("%d ",real[i]);
	}
	return 0;
}
