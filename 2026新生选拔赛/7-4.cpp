#include <bits/stdc++.h>
using namespace std;
int main()
{
    char arr[105];
    char a;
    int k=0;
    while(scanf(" %c",&a)==1)
        {
            arr[k++]=a;
        }
    deque <char> de;
    int len1=strlen(arr);
    for(int i=0;i<len1;i++)
        {
            if(arr[i]=='('||arr[i]=='['||arr[i]=='{')
            {
                de.push_back(arr[i]);
            }
            else if(arr[i]==')'||arr[i]==']'||arr[i]=='}')
            {
                if(arr[i]==')')
                {
                    if(de.back()=='(')
                    {
                        de.pop_back();
                    }
                    else
                    {
                        cout<<'no'<<endl;
                        return 0;
                    }
                }
                else if(arr[i]==']')
                {
                    if(de.back()=='[')
                    {
                        de.pop_back();
                    }
                    else
                    {
                        cout<<'no'<<endl;
                        return 0;
                    }
                }
                else if(arr[i]=='}')
                {
                    if(de.back()=='{')
                    {
                        de.pop_back();
                    }
                    else
                    {
                        cout<<'no'<<endl;
                        return 0;
                    }
                }
            }
        }
    if(de.empty()) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
    return 0;
}