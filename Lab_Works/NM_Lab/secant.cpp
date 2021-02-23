#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double fun1(double x)
{
    return pow(x,3)-3*pow(x,2)+2*x-2;
}
double fun2(double x)
{
    return x*sin(x)+cos(x);
}
double fun3(double x)
{
    return pow(x,2)+4*x+5;
}

void cal(double(*fun)(double))
{
    double a,b,c,tol;
    cout<<"Enter initial interval(a,b): ";
    cin>>a>>b;
    cout<<"Enter tolerance: ";
    cin>>tol; 
    const int width=15;
    cout<<left;
    cout<<setw(width)<<"S.N"<<setw(width)<<"a"<<setw(width)<<"b"<<setw(width)<<"c"<<setw(width)<<"f(c)"<<endl<<endl;
    bool noSoln=false;
    int i=1;
    do
    {
            c=(a*fun(b)-b*fun(a))/(fun(b)-fun(a));
            cout<<setw(width)<<i<<"."<<setprecision(6)<<setw(width)<<a<<setw(width)<<b<<setw(width)<<c<<setw(width)<<fun(c)<<endl;
            
            a=b;
            b=c;
            i++;
            if(i>30)
            {
                noSoln=true;
                break;
            }
    }while(abs(fun(c))>=tol);
    if(!noSoln)
        cout<<"The root is: "<<c<<endl<<endl;
    else//exceeded 30 iteration;
    {
        cout<<endl<<"30 iterations exceeded.No soln is found. "<<endl<<endl;
    }
}
int main()
{

    cout<<"For Equation: x^3-3x^2+2x-2"<<endl<<endl;
    cal(fun1);
    cout<<"For Equation: xsinx+cosx"<<endl<<endl;
    cal(fun2);
    cout<<"For Equation: x^2+4x+5"<<endl<<endl;
    cal(fun3);
    return 0;
}
