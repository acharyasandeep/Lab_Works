//Euler's method of solving differential equation
//xn+1 = xn + h
//yn+1 = yn + hf(xn,yn)

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double f(double x, double y)
{
    return 2*x+sin(y);
}
int main()
{
    double x, y, h, xn,yn;
    int n;
    cout<<"For 2x+sin(y)\n\n";
    cout<<"Initial Condition(x0,y0): ";cin>>x>>y;
    cout<<"Final value of x(xn): ";cin>>xn;
    cout<<"No. of steps: ";cin>>n;
    h = (xn-x)/n;
    cout<<left;
    cout<<setprecision(6);
    cout<<setw(10)<<"X"<<setw(10)<<"Y"<<setw(10)<<"Slope"<<setw(10)<<"Ynew"<<endl;
    for(int i=0;i<=n;i++)
    {

        cout<<setw(10)<<x<<setw(10)<<y<<setw(10)<<f(x,y);
        double k = h*f(x,y);
        yn = y;
        y = y+k;
        x = x+h;
        cout<<setw(10)<<y<<endl;
    }
    cout<<"At x = "<<xn<<" y = "<<yn<<endl;
    return 0;
}
