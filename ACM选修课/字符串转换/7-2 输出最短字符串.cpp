#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    cin.ignore();
    string arr[n];
    int min=5000,hao=0;
    for(int i=0;i<n;i++)
    {
        getline(cin,arr[i]);
        int l=arr[i].size();
        if(l<min)
        {
            min=l;
            hao=i;
        }
    }
    cout<<arr[hao]<<endl;
    return 0;
}