#include <bits/stdc++.h>
using namespace std;
#define Small 1000005
int myheap[Small];
int height=0;
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
    int n,x;
    cin>>n;
    while(n--)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            int x;
            cin>>x;
            push(x);
        }
        else if(op==2)
        {
            cout<<myheap[1]<<endl;
        }
        else if(op==3)
        {
            pop();
        }
    }
    return 0;
}