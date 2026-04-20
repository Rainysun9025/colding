#include <bits/stdc++.h>
using namespace std;
int main()
{
    char s[100];
    int n;
    cin>>n;
    while(n--)
        {
            scanf("%s",s);
            if(s[0]=='R')
            {
                cout<<"Paper "<<endl;
            }
            else if(s[0]=='S')
            {
                cout<<"Rock "<<endl;
            }
            else
            {
                cout<<"Scissors "<<endl;
            }
            
        }
    return 0;
}