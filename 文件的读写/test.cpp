#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream ofs;
    ofs.open("test.txt", ios::out);
    if (!ofs) {   // 检查是否成功打开
        cerr << "文件打开失败！" << endl;
        return 1;
    }

    for (int i = 0; i <= 1000; i++) {
        ofs << "你好" << endl;
    }

    ofs.close();  // 显式关闭（也可以依赖析构函数自动关闭）
    return 0;
}