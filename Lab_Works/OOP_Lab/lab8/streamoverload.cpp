#include <iostream>
using namespace std;
class Complex
{
private:
    int real,imag;
public:
    Complex(int areal =0, int aimag=0)
    {
        real = areal;
        imag = aimag;
    }
    friend ostream &operator<<(ostream &,Complex);
};
ostream &operator <<(ostream &out, Complex c1)
    {
        out<<c1.real;
        out<< " +i"<<c1.imag;
        return out;
    }
int  main()
{
    Complex c1(6,4);
    cout<<c1;
}
