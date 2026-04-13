#include <iostream>
using namespace std;
int main()
{
  long long n;
  cin>>n;
  long long arr[n];
  long long sum=0;
  for(long long i=0;i<n;i++)
  {
    cin>>arr[i];
    sum+=arr[i];
  }
  long long cur=0;
  long long ans=sum;
  long long k=-1;
  for(long long i=0;i<n-1;i++)
  {
    cur+=arr[i];
    long long r=sum-cur;
    if(cur==r)
    {
        cout<<"0"<<endl;
        return 0;
    }
    else if(cur<r)
    {
        ans=r-cur;
    }
    else if(cur>r)
    {
        k=cur-r;
        break;
    }
  }
  if(k==-1)
  {
    cout<<ans<<endl;
    return 0;
  }
  else
  {
    if(k<ans) ans=k;
    cout<<ans<<endl;
    return 0;
  }
  return 0;
}