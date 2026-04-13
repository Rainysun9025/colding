#include <iostream>
using namespace std;
int main()
{
  int n;
  double k;
  cin>>n;
  cin>>k;
  int t=1;
  for(int i=1;i<=n;i++)
  {
    t=t*2;
  }
  double ans=k*t;
  int p=(int)ans;
  double yv=ans-p;
  if(yv>=0.5)
  {
    cout<<p+1;
    return 0;
  }
  else
  {
    cout<<p;
    return 0;
  }
  return 0;
}