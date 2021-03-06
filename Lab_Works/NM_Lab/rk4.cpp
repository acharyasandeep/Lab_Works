//rk4
//rk2 method for solving diff equation
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double f(double x, double y)
{
    return sin(x)+cos(y);
    //return 2*x + sin(y);
    //return x + pow(y,0.5);
}
int main()
{
    double x, y, h, xn,yn;
    int n;
    cout<<"For function sin(x)+cos(y) \n\n";
    cout<<"Initial Condition(x0,y0): ";cin>>x>>y;
    cout<<"Final value of x(xn): ";cin>>xn;
    cout<<"No. of steps: ";cin>>n;
    h = (xn-x)/n;
    cout<<left;
    cout<<setprecision(6);
    cout<<setw(10)<<"X"<<setw(10)<<"Y"<<setw(10)<<"Ynew"<<endl;
    for(int i=0;i<=n;i++)
    {

        cout<<setw(10)<<x<<setw(10)<<y;
        double k1 = h*f(x,y);
        double k2 = h*f(x+h/2,y+k1/2);
        double k3 = h*f(x+h/2,y+k2/2);
        double k4 = h*f(x+h,y+k3);
        double k = (k1+2*k2+2*k3+k4)/6;
        yn = y;
        y = y+k;
        x = x+h;
        cout<<setw(10)<<y<<endl;
    }
    cout<<"At x = "<<xn<<", y = "<<yn<<endl;
    return 0;
}


