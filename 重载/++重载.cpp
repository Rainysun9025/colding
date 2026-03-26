#include <iostream>
using namespace std;
struct person
{
    friend ostream& operator<<(ostream& cout,const person &p);
    friend person& operator++(person& p);
    friend person operator++(person& p,int);
    public:
    person()
    {
        ma=10;
        mb=20;
        mc=30;
    }
    private:
    int ma,mb,mc;
};
ostream& operator<<(ostream& cout,const person &p)
{
    cout<<p.ma<<endl<<p.mb<<endl<<p.mc<<endl;
    return cout;
}
person& operator++(person& p)
{
    p.ma++;p.mb++;p.mc++;
    return p;
}
person operator++(person& p,int)
{
    person temp = p;
    p.ma++;p.mb++;p.mc++;
    return temp;
}
int main()
{
    person lc;
    cout<<"重载输出"<<endl<<lc<<endl;
    cout<<"重载前置++"<<endl<<++lc;
    cout<<"重载后置++"<<endl<<lc++;
    cout<<"-----------------------"<<endl;
    cout<<lc;
    return 0;
}