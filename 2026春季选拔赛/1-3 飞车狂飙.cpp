#include <bits/stdc++.h>
using namespace std;
int cmp(const void*a,const void* b)
{
    int *pa=(int *)a;
    int *pb=(int *)b;
    if(pa[0]!=pb[0]) return pa[0]-pb[0];
    else if(pa[0]==pb[0])
    {
        return pa[1]-pb[1];
    }
}
int main()
{
    int T;
    cin>>T;
    while(T--)
        {
            int n;
            cin>>n;
            char arr[n+5];
            scanf("%s",arr);
            int len1=strlen(arr);
            int fangxiang=3;
            //1 左
            //2 下
            //3 右
            //5 上
            int lc[n+10][2];
            int k=0;
            int curx=0,cury=0;
            for(int i=0;i<n;i++)
                {
                    int nextx,nexty;
                    if(fangxiang==3)
                    {
                        if(arr[i]=='S')
                        {
                            nexty=cury;
                            nextx=curx+1;
                        }
                        else if(arr[i]=='L')
                        {
                            nexty=cury;
                            nextx=curx+1;
                            fangxiang=5;
                        }
                        else if(arr[i]=='R')
                        {
                            nexty=cury;
                            nextx=curx+1;
                            fangxiang=2;
                        }
                        lc[k][0]=nextx;
                        lc[k++][1]=nexty;
                    }
                    else if(fangxiang==1)
                    {
                        if(arr[i]=='S')
                        {
                            nextx=curx-1;
                            nexty=cury;
                        }
                        else if(arr[i]=='L')
                        {
                            nextx=curx-1;
                            nexty=cury;
                            fangxiang=2;
                        }
                        else if(arr[i]=='R')
                        {
                            nextx=curx-1;
                            nexty=cury;
                            fangxiang=5;
                        }
                        lc[k][0]=nextx;
                        lc[k++][1]=nexty;
                    }
                    else if(fangxiang==2)
                    {
                        if(arr[i]=='S')
                        {
                            nextx=curx;
                            nexty=cury-1;
                        }
                        else if(arr[i]=='L')
                        {
                            nextx=curx;
                            nexty=cury-1;
                            fangxiang=3;
                        }
                        else if(arr[i]=='R')
                        {
                            nextx=curx;
                            nexty=cury-1;
                            fangxiang=1;
                        }
                        lc[k][0]=nextx;
                        lc[k++][1]=nexty;
                    }
                    else if(fangxiang==5)
                    {
                        if(arr[i]=='S')
                        {
                            nextx=curx;
                            nexty=cury+1;
                        }
                        else if(arr[i]=='L')
                        {
                            nextx=curx;
                            nexty=cury+1;
                            fangxiang=1;
                        }
                        else if(arr[i]=='R')
                        {
                            nextx=curx;
                            nexty=cury+1;
                            fangxiang=3;
                        }
                        lc[k][0]=nextx;
                        lc[k++][1]=nexty;
                    }
                    curx=nextx;
                    cury=nexty;
                }
            //cout<<"k=";
            //cout<<k<<endl;
            bool chenghuan=false;
            int stx=lc[0][0],sty=lc[0][1];
            int zx=lc[k-1][0],zy=lc[k-1][1];
            //if(stx==zx&&sty==zy) chenghuan=true;
            //cout<<stx<<" "<<sty<<endl;
            //cout<<zx<<" "<<zy<<endl;
            if(zx==0&&zy==0&&fangxiang==3) chenghuan=true;
            /*for(int i=0;i<k;i++)
                {
                    cout<<lc[i][0]<<" "<<lc[i][1]<<endl;
                }*/
            qsort(lc,k,sizeof(int)*2,cmp);
            bool chongdie=false;
            for(int i=0;i<k-1;i++)
                {
                    if(lc[i][0]==lc[i+1][0]&&lc[i][1]==lc[i+1][1])
                    {
                        chongdie=true;
                        break;
                    }
                }
            if(k==1)
            {
                cout<<"0"<<endl;
                continue;
            }
            if(chongdie==true)
            {
                cout<<"-1"<<endl;
                continue;
            }
            else if(chenghuan==true)
            {
                cout<<"1"<<endl;
                continue;
            }
            else if(chenghuan==false)
            {
                cout<<"0"<<endl;
                continue;
            }
        }
    return 0;
}