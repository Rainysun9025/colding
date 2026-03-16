#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        char a[1005];
        scanf("%s",a);
        int arr[1005];
        int len1=strlen(a);
        for(int i=0;i<len1;i++)
        {
            arr[i]=a[i]-'0';
            arr[i]*=6;
        }
        for(int i=len1-1;i>=1;i--)
        {
            int m,p;
            m=arr[i]/2;
            p=arr[i]%2;
            arr[i-1]+=m;
            arr[i]=p;
        }
        int st[1005];
        int k=1004;
        while(arr[0]>1)
        {
            int q=arr[0]%2;
            st[k]=q;
            arr[0]=arr[0]/2;
            k--;
        }
        st[k]=arr[0];
        if(st[k]==1) cout<<st[k];
        for(int i=k+1;i<1005;i++) cout<<st[i];
        for(int i=1;i<len1;i++) cout<<arr[i];
        cout<<endl;
    }
    return 0;
}