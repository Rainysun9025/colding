#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
        {
            int num_k,num_x;
            cin>>num_k>>num_x;
            int ke[100005][2];
            int xiu[100005][2];
            for(int i=0;i<num_k;i++) cin>>ke[i][0]>>ke[i][1];
            for(int i=0;i<num_x;i++) cin>>xiu[i][0]>>xiu[i][1];
            int youxiao[100005][2];
            int k=0;
            int t=0;
            for(int i=0;i<num_k;i++)
                {
                    int curstar=ke[i][0];
                    int curover=ke[i][1];
                    while(k<num_x&&xiu[k][1]<=ke[i][1])
                        {
                            if(xiu[k][1]<=ke[i][0])
                            {
                                youxiao[t][0]=xiu[k][0];
                                youxiao[t][1]=xiu[k][1];
                                t++;
                                k++;
                            }
                            else if(xiu[k][1]>ke[i][0])
                            {
                            	k++;
							}
                        }
                }
            long long over=0;
            k=0;
            bool ans=true;
            for(int i=0;i<num_k;i++)
                {
                    while(k<t&&youxiao[k][1]<=ke[i][0])
                        {
                            long long curover=youxiao[k][1]+2*(youxiao[k][1]-youxiao[k][0]);
                            if(curover>over) over=curover;
                            k++;
                        }
                    if(over>=ke[i][1]) continue;
                    else if(over<ke[i][1])
                    {
                        ans=false;
                        break;
                    }
                }
            if(ans==true) cout<<"Yes"<<endl;
            else if(ans==false) cout<<"No"<<endl;
		}
		return 0;
}