#include <bits/stdc++.h>
using namespace std;
int main()
{
    while(1)
    {
        char arr[105];
        if(scanf("%s",arr)==EOF) return 0;
        int len1=strlen(arr);
        int a=0,b=len1-1;
        int num=0;
        bool ky=true;
        while(a<=b)
        {
            if(a==b)
            {
                if(num==0)
                {
                    num++;
                    break;
                }
            }
            if(arr[a]==arr[b]) 
            {
                a++,b--;
                continue;
            }
            else
            {
                if(num==0)
                {
                    num++;
                    a++,b--;
                    continue;
                }
                ky=false;
                break;
            }

        }
        if(ky==true&&num==1)
        {
            cout<<"YES"<<endl;
            continue;
        }
        else
        {
            cout<<"NO"<<endl;
            continue;
        }
    }
    return 0;
}