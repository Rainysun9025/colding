#include <bits/stdc++.h>
using namespace std;
int cmp(const void*a,const void* b)
{
    int *pa=(int *)a;
    int *pb=(int *)b;
    return *pa-*pb;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
        {
            int ans=0;
            int n,x,k;
            //敌人的数量，故障机器人的初始生命值,烟雾弹的数量
            cin>>n>>x>>k;
            int arr[n];
            for(int i=0;i<n;i++) cin>>arr[i];
            if(k==0&&arr[0]>=x)
            {
                cout<<"0"<<endl;
                continue;
            }
            int left=1,right=n,mid;
            while(left<=right)
                {
                    int xue=x;
                    int tk=k;
                    mid=(left+right)/2;
                    int temp[mid];
                    for(int i=0;i<mid;i++) temp[i]=arr[i];
                    qsort(temp,mid,sizeof(int),cmp);
                    /*cout<<mid<<endl;
                    for(int i=0;i<mid;i++) cout<<temp[i]<<" ";
                    cout<<endl;*/
                    if(tk>=mid)
                    {
                    	ans=mid;
                    	left=mid+1;
                    	continue;
					}
					for(int i=0;i<mid-tk;i++)
					{
						xue-=temp[i];
					}
					if(xue<=0)
					{
						right=mid-1;
						continue;
					}
					else if(xue>0)
					{
						ans=mid;
						left=mid+1;
						continue;
					}
                }
            cout<<ans<<endl;
        }
    return 0;
}