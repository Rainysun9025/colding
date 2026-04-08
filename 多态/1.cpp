#include <iostream>
using namespace std;
struct Animal
{
public:
    virtual  void speak()
    {
        cout<<"动物在说话"<<endl;
    }
};
struct Cat:public Animal
{
    void speak()
    {
        cout<<"猫在说话"<<endl;
    }
};
void dospeak(Animal& animal)
{
    animal.speak();
    return;
}
int main()
{
    Animal animal;
    Cat cat;
    dospeak(cat);
    return 0;
}

