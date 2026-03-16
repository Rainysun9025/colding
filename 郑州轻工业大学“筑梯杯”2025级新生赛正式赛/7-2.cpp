#include <bits/stdc++.h>
using namespace std;
void jiaohuan(char *arr,int len1,int i)
{
    char temp=arr[len1-1];
    arr[len1-1]=arr[i];
    arr[i]=temp;
    return;
}
int main()
{
    /*首先从左到右遍历，如果发现这个数是偶数，就比较他和最后一个数的相对大小
    如果最后一个数比他大，直接换，然后退出
    如果比他小，先换，然后继续遍历
    这个时候整体数是变小的
    然后继续遍历，如果后面有数字是偶数，并且比原来的最后一个数小，换，因为这时候整体数就变大了
    如果比原来的最后一个数大，换，因为这个时候虽然整体数还是变小，但是变小的程度没有原来那么厉害了
    最后输出*/
    int t;
    cin>>t;
    while(t--)
    {
        bool really=false;
        int xiaoyv=-1;
        char arr[105];
        scanf("%s",arr);
        int len1=strlen(arr);
        int last=arr[len1-1]-'0';
        for(int i=0;i<len1-1;i++)
        {
            int cur=arr[i]-'0';
            if(cur%2!=0) continue;
            if(cur<last)
            {
                jiaohuan(arr,len1,i);
                really=true;
                break;
            }
            else xiaoyv=i;
        }
        if(really==false&&xiaoyv==-1)
        {
            cout<<"-1"<<endl;
        }
        else if(really==true)
        {
            cout<<arr<<endl;
        }
        else if(xiaoyv!=-1)
        {
            jiaohuan(arr,len1,xiaoyv);
            cout<<arr<<endl;
        }
    }
    return 0;
}