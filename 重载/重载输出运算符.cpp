#include <iostream>
using namespace std;
struct person
    {
        public:
        friend ostream& operator<<(ostream &cout,const person &p);
        person()
        {
            ma=10;mb=10;
        }
        private:
        int ma,mb;
    };
ostream& operator<<(ostream &cout,const person &p)
    {
        cout<<"p.ma是"<<p.ma<<endl;
        cout<<"p.mb是"<<p.mb<<endl;
        return cout;
    }
//用引用的写法而不是ostream
/*
1 ostream 不能拷贝，所以不能按值返回 ostream
2 返回 ostream& 可以返回原来的输出流对象
3 返回引用可以支持链式调用：
*/
    
int main()
{
    person p1,p2;
    cout<<p1<<p2;
    return 0;
}