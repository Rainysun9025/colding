#include <stdio.h>
void change(int arr[5][5],int x,int y)
{
    arr[x][y]^=1;
    if(x-1>=0) arr[x-1][y]^=1;
    if(x+1<=4) arr[x+1][y]^=1;
    if(y-1>=0) arr[x][y-1]^=1;
    if(y+1<=4) arr[x][y+1]^=1;
    return;
}
int main()
{
    int n;
    scanf("%d",&n);
    int arr[5][5],copy[5][5];
    int i,u,l,k,t;
    int num_1,num_2,num_3,num_4,num_5;
    int ans=0;
    int min=1000000;
    int biao=1;
    for(i=1;i<=n;i++)
    {
        min=1000000;
        for(u=0;u<5;u++)
        {
            for(l=0;l<5;l++)
            {
                scanf("%1d",&arr[u][l]);
                copy[u][l]=arr[u][l];
            }
        }
        for(num_1=0;num_1<=1;num_1++)
        {
            for(num_2=0;num_2<=1;num_2++)
            {
                for(num_3=0;num_3<=1;num_3++)
                {
                    for(num_4=0;num_4<=1;num_4++)
                    {
                        for(num_5=0;num_5<=1;num_5++)
                        {
                            biao=1;
                            for(k=0;k<5;k++)
                            {
                                for(t=0;t<5;t++)
                                {
                                    arr[k][t]=copy[k][t];
                                }
                            }
                            ans=0;
                            if(num_1==1) {change(arr,0,0);ans++;};
                            if(num_2==1) {change(arr,0,1);ans++;};
                            if(num_3==1) {change(arr,0,2);ans++;};
                            if(num_4==1) {change(arr,0,3);ans++;};
                            if(num_5==1) {change(arr,0,4);ans++;};
                            for(k=0;k<5;k++)
                            {
                                if(arr[0][k]==0) {change(arr,1,k);ans++;}
                            }
                            for(k=0;k<5;k++)
                            {
                                if(arr[1][k]==0) {change(arr,2,k);ans++;}
                            }
                            for(k=0;k<5;k++)
                            {
                                if(arr[2][k]==0) {change(arr,3,k);ans++;}
                            }
                            for(k=0;k<5;k++)
                            {
                                if(arr[3][k]==0) {change(arr,4,k);ans++;}
                            }
                            for(k=0;k<5;k++)
                            {
                                for(t=0;t<5;t++)
                                {
                                    if(arr[k][t]==0)
                                    {
                                        biao=0;break;
                                    }
                                }
                            }
                            if(biao==0) continue;
                            else
                            {
                                    if(ans<min) min=ans;
                            }
                        }
                    }
                }
            }
        }
        if(min>6) printf("-1\n");
        else printf("%d\n",min);
    }
    return 0;
}
