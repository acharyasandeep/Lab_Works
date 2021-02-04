//Read Comments
#include <iostream>
class testclass
{
private:
    int x,y;
public:
    testclass(int ax,int ay):x(ax),y(ay) {}
    void testfunc () const
    {
        std::cout<<"Successfully Called Constant member function\n";
    }

    void testfunc1 ()
    {
        x = 1;
        y = 2;
        std::cout<<"Successfully Called non-constant member function\n";
    }
};
int main()
{
    testclass test1(4,5);
    const testclass test2(9,11);
    test1.testfunc(); //fine works
    test1.testfunc1(); //fine works
    test2.testfunc(); //fine works
    test2.testfunc1(); //Error :: Doesn't work
}
