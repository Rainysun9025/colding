#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,n,m;
    cin>>a>>b>>c>>n>>m;
    double deerta;
    deerta=sqrt((b-n)*(b-n)-4*a*(c-m));
    double x1,x2;
    x1=((n-b)+deerta*1.0)/(2*a);
    x2=((n-b)-deerta*1.0)/(2*a);
    double ans=fabs(a)*1.0/6;
    ans*=fabs(x1-x2)*fabs(x1-x2)*fabs(x1-x2);
    cout<<ans;
    return 0;
}
