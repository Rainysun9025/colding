#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    set <string> s;
    while(n--)
    {
        string k;
        cin>>k;
        s.insert(k);
    }
    cout<<s.size()<<endl;
    return 0;
}