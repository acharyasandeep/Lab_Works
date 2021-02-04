#include <iostream>
class testthis
{
    int x;
public:
    void func()
    {
        std::cout<<"This object has an address: "<<this<<"\n";
    }
};
int main()
{
    testthis t1,t2;
    t1.func();
    t2.func();
}
