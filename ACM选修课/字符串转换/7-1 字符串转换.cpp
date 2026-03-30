#include <bits/stdc++.h>
using namespace std;
int main()
{
    char arr[105];
    int temp[105];
    int k=0;
    temp[0]=0;
    scanf("%s",arr);
    int len1=strlen(arr);
    for(int i=0;i<len1;i++)
    {
        if(isdigit(arr[i]))
        {
            temp[k++]=(arr[i]-'0')*2;
        }
    }
    for(int i=k-1;i>=1;i--)
    {
        int a=temp[i]/10;
        int b=temp[i]%10;
        temp[i]=b;
        temp[i-1]+=a;
    }
    /*string ans;
    ans=to_string(temp[0]);
    for(int i=1;i<k;i++)
    {
        ans+=to_string(temp[i]);
    }
    int num=stoi(ans);
    ans=to_string(num);
    cout<<ans;
    return 0;
    */
   if(k==0)
   {
    cout<<"0"<<endl;
    return 0;
   }
   int start=0;
   while(temp[start]==0)
   {
        start++;
        if(start==k)
        {
            cout<<"0"<<endl;
            return 0;
        }
   }
   for(int i=start;i<k;i++)
   {
    cout<<temp[i];
   }
   cout<<endl;
   return 0;
}