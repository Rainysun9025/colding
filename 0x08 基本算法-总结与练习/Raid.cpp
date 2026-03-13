#include <bits/stdc++.h>
using namespace std;
const double INF = 1e20;
struct point{
	int x;
	int y;
	int num;
}a[200005],b[200005];
bool cmpx(const point &p,const point &q)
{
	return p.x==q.x?p.y<q.y:p.x<q.x;
}
bool cmpy(const point &p,const point &q)
{
	return p.y<q.y;
}
double dis(const point &p,const point &q)
{
	double X=fabs(p.x-q.x);
	double Y=fabs(p.y-q.y);
	return sqrt(X*X+Y*Y);
}
double solve(int l,int r)
{
	if(l==r) return INF;
	else if(l+1==r)
	{
		if(a[l].num==a[r].num) return INF;
		else return dis(a[l],a[r]);
	}
	int m=(l+r)>>1;
	double d=min(solve(l,m),solve(m+1,r));
	if(d==INF)
	{
		d=dis(a[m],a[m+1]);
	} 
	int k=0;
	for(int i=l;i<=r;i++)
	{
		if(fabs(a[i].x-a[m].x)<=d) b[++k]=a[i];
	}
	sort(b+1,b+1+k,cmpy);
	for(int i=1;i<=k;i++)
	{
		for(int u=i+1;u<=k;u++)
		{
			if(b[u].num==b[i].num) continue;
			if(b[u].y-b[i].y>=d) break;
			d=min(d,dis(b[u],b[i]));
		}
	}
	return d;
}
int main()
{
	int T;
	cin>>T;
	for(T;T>0;T--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int x1,y1;
			cin>>x1>>y1;
			a[i].x=x1;
			a[i].y=y1;
			a[i].num=1;
		}
		for(int i=n+1;i<=n+n;i++)
		{
			int x1,y1;
			cin>>x1>>y1;
			a[i].x=x1;
			a[i].y=y1;
			a[i].num=2;
		}
		sort(a+1,a+1+n+n,cmpx); 
		double ans=solve(1,2*n);
		printf("%.3f\n",ans);
	}
	return 0;
 } 
 
