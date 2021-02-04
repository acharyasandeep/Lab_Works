#include <iostream>
using namespace std;
class Complex
{
public:
    int real, imag;
    Complex ()
    {
        cout<<"Enter real part: "; cin>>real;
        cout<<"Enter imaginary part: ";cin>>imag;
    }

    void display()
    {
        cout<<real<<" +i "<<imag<<" ";
    }
};
class Compl:public Complex
{
public:
    Compl() {}
    Compl &operator+ (const Complex c)
    {
        real +=c.real;
        imag +=c.imag;
        return *this;
    }
};
int main()
{
    Complex c1;
    Compl c2;
    c1.display();
    std::cout<<" + ";
    c2.display();
    cout<<" = ";

    c2 = c2+c1;
    c2.display();
}
