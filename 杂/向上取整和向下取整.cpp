#include <bits/stdc++.h>
using namespace std;
//对a/b，结果是向零取整
long long upup(long long a,long long b)//计算a/b向上取整
{
    long long m,n;
    m=a/b;
    n=a%b;
    if(n==0)
    {
        //刚好整除，直接返回
        return m;
    }
    else if((a>0&&b>0)||(a<0&&b<0))//有余数，并且除数和被除数是同号
    {
        m++;
        return m; 
    }
    else if((a>0&&b<0)||(a<0&&b>0))//有余数，并且除数和被除数是异号,其实可以直接写else
    {
        return m;
    }
}
long long lowlow(long long a,long long b)//计算a/b向下取整
{
    long long m,n;
    m=a/b;
    n=a%b;
    if(n==0)
    {
        //刚好整除，直接返回
        return m;
    }
    else if((a>0&&b>0)||(a<0&&b<0))//有余数，并且除数和被除数是同号
    {
        return m;
    }
    else if((a>0&&b<0)||(a<0&&b>0))//有余数，并且除数和被除数是异号,其实可以直接写else
    {
        m--;
        return m;
    }
}