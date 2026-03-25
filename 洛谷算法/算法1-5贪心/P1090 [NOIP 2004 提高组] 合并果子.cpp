#include <bits/stdc++.h>
using namespace std;
#define Small 1000005
long long myheap[Small];
long long height=0;
void push(int x)
{
    myheap[++height]=x;
    int i=height;
    while(i>1&&myheap[i]<myheap[i/2])
    {
        swap(myheap[i],myheap[i/2]);
        i=i/2;
    }
    return;
}
void pop()
{
    if(height==0) return;
    myheap[1]=myheap[height--];
    int i=1;
    int son=i*2;
    while(son<=height)
    {
        if(son+1<=height&&myheap[son]>myheap[son+1])
        {
            son++;
        }
        if(myheap[i]>myheap[son])
        {
            swap(myheap[i],myheap[son]);
            i=son;
            son=i*2;
        }
        else break;
    }
    return;
}
int main()
{
    long long n;
    cin>>n;
    int temp[n];
    for(long long i=0;i<n;i++) cin>>temp[i];
    sort(temp,temp+n);
    for(long long i=1;i<=n;i++)
    {
        myheap[i]=temp[i-1];
    }
    long long sum=0;
    height=n;
    for(long long i=1;i<=n-1;i++)
    {
        long long cur=0;
        cur+=myheap[1];
        pop();
        cur+=myheap[1];
        pop();
        push(cur);
        sum+=cur;
    }
    cout<<sum<<endl;
    return 0;
}