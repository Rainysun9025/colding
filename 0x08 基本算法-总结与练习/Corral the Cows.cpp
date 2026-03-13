#include <bits/stdc++.h>
using namespace std;
struct lc{
	int x;
	int y;
} arr[1005],b[1005];
bool cmpy(const lc&a,const lc&b){
	return a.y<b.y;
}
int main()
{
	int ans=0;
	int req,n;
	cin>>req>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i].x>>arr[i].y;
	}
	int left,right,mid;
	left=1;
	right=10005;
	while(left<=right){
		mid=(left+right)>>1;
		int biao=0;
		for(int i=1;i<=n;i++){
			int l=arr[i].x,r=l+mid;
			int k=0;
			for(int u=1;u<=n;u++){
				if(arr[u].x>=l&&arr[u].x+1<=r) b[++k]=arr[u];
			}
			//b[1] b[2] b[3] ...... b[k]
			sort(b+1,b+k+1,cmpy);
			int o=1;
			for (int p = 1; p <= k; ++p) {
    			while (o < p && b[p].y - b[o].y + 1> mid) {
        			++o;
    			}
    			if (p - o + 1 >= req) {
       			biao = 1;
        		break;
    			}
			}
			if(biao) break;
		}
		if(biao){
			ans=mid;
			right=mid-1;
		}else{
			left=mid+1;continue;
		}
	}
	cout<<ans;
}
