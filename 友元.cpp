#include <bits/stdc++.h>
using namespace std;
struct biuld
{
  friend void visit();
  public:
  string sittingroom;
  private:
  string bedroom;
  biuld()
  {
    sittingroom="哈吉鹏的客厅";
    bedroom="阳崽的卧室";
  }
};
void visit()
{
    biuld a;
    biuld b;
    cout<<"visit函数正在访问"<<a.sittingroom<<endl;
    cout<<"visit函数正在访问"<<a.bedroom<<endl;
}
int main()
{
    visit();
    return 0;
}