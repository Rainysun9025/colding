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
    
int main()
{
    person p1;
    cout<<p1;
    return 0;
}