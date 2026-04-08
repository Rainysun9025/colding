#include <iostream>
#include <fstream>
using namespace std;
void test01()
{
    ofstream ofs;
    ofs.open("test.txt",ios::out);
    ofs<<"你好"<<endl;
}
int main()
{
    test01();
    return 0;
}