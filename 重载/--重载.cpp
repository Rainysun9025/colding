#include <iostream>
using namespace std;
struct person
{
    friend ostream& operator<<(ostream& cout,const person &p);
    friend person& operator--(person& p);
    friend person operator--(person& p,int);
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
person& operator--(person& p)// 前置 --
{
    p.ma--;p.mb--;p.mc--;
    return p;
}
person operator--(person& p,int)// 后置 --
{
    
    person temp = p;// 保存减之前的值
    p.ma--;p.mb--;p.mc--;
    return temp;//返回旧值

    //后置 -- 返回旧值副本，所以用普通对象
    //这里的后置--返回值类型不能写成 person& 因为temp是局部变量，函数结束就销毁，这会产生悬空引用！
}
int main()
{
    person lc;
    cout<<"重载输出"<<endl<<lc<<endl;
    cout<<"重载前置--"<<endl<<--lc;
    cout<<"重载后置--"<<endl<<lc--;
    cout<<"-----------------------"<<endl;
    cout<<lc;
    return 0;
}