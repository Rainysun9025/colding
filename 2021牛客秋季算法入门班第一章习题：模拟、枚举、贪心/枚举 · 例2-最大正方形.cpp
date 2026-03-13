#include <stdio.h>
#include <math.h>

double cal_1x(int x1,int y1,int x2,int y2)
{
    return (1.0*x1+x2-(y1-y2))/2;
}
double cal_1y(int x1,int y1,int x2,int y2)
{
    return (1.0*y1+y2+(x1-x2))/2;
}
double cal_2x(int x1,int y1,int x2,int y2)
{
    return (1.0*x1+x2+(y1-y2))/2;
}
double cal_2y(int x1,int y1,int x2,int y2)
{
    return (1.0*y1+y2-(x1-x2))/2;
}
double cal_len(int x1,int y1,int x2,int y2)
{
    double X1,X2,Y1,Y2;
    X1=(double)x1;Y1=(double)y1;X2=(double)x2;Y2=(double)y2;
    double oo,pp;
    oo=(X2-X1)*(X2-X1);pp=(Y2-Y1)*(Y2-Y1);
    double answer;
    answer=pow((oo+pp)/2,0.5);
    return answer;
}
void swap(int *x,int *y)
{
    int temp;
    temp=*y;
    *y=*x;
    *x=temp;
}
int main()
{
    int n;
    double ans;
    double max=-1;
    double new_1x,new_1y,new_2x,new_2y;
    int ans_x1,ans_x2,ans_y1,ans_y2,ans_x3,ans_y3,ans_x4,ans_y4;
    scanf("%d",&n);
    getchar();
    char a[n][n];
    int i,u;
    int m,t;
    for(i=0;i<n;i++)
    {
        for(u=0;u<n;u++)
        {
            scanf("%c",&a[i][u]);
        }
        getchar();
    }
    //读取数据完毕
    for(i=0;i<n;i++)
    {
        for(u=0;u<n;u++)
        {
            if(a[i][u]=='#')//找到正方形第一个顶点
            {
                m=i;t=u;
                for(m;m<n;m++)
                {
                    for(t;t<n;t++)
                    {
                        if(m==i&&t==u) continue;
                        if(a[m][t]=='#')//找到正方形与第一个顶点对角的那个顶点
                        {
                            new_1x= cal_1x(i,u,m,t);
                            new_1y= cal_1y(i,u,m,t);
                            new_2x= cal_2x(i,u,m,t);
                            new_2y= cal_2y(i,u,m,t);
                            if(new_1x<0||new_1y<0||new_2x<0||new_2y<0) break;//其坐标不能小于数组最小下标0
                            if(new_1x>=n||new_1y>=n||new_2x>=n||new_2y>=n) break;//其坐标不能大于数组最大下标n-1
                            if(new_1x!=(int)new_1x&&new_1y!=(int)new_1y&&new_2x!=(int)new_2x&&new_2y!=(int)new_2y) break;//其坐标必须是一个整数
                            if(a[(int)new_1x][(int)new_1y]!='#'||a[(int)new_2x][(int)new_2y]!='#') break;//其坐标对应的符号必须都是#
                            ans=cal_len(i,u,m,t);//计算正方形边长
                            if(ans>max)
                            {
                                max=ans;
                                ans_x1=i;ans_y1=u;ans_x2=m;ans_y2=t;
                                ans_x3=new_1x;ans_y3=new_1y;
                                ans_x4=new_2x;ans_y4=new_2y;//记录最终答案
                            }
                            
                        }
                    }
                    t=0;
                }
            }
        }
    }
    int kk;
    int key_x[4]={ans_x1+1,ans_x2+1,ans_x3+1,ans_x4+1},key_y[4]={ans_y1+1,ans_y2+1,ans_y3+1,ans_y4+1};
    for(i=0;i<3;i++)
    {
        for(u=0;u<3-i;u++)
        {
            if(key_x[u] > key_x[u+1] || (key_x[u] == key_x[u+1] && key_y[u] > key_y[u+1]))
            {
                swap(&key_x[u],&key_x[u+1]);
                swap(&key_y[u],&key_y[u+1]);
            }
        }
    }
    
    for(kk=0;kk<4;kk++)
    {
        printf("%d %d\n",key_x[kk],key_y[kk]);
    }
    return 0;
}
