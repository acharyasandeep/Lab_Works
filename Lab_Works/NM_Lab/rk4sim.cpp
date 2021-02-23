//rk4 simultaneous equations

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double f(double x, double y, double z)
{
    return x+y+z;
}
double g(double x, double y, double z)
{
    return 1+y+z;
}
int main()
{
    double x, y, z, h, xn,yn,zn;
    int n;
    cout<<"For functions f(x,y,z) = x+y+z and g(x,y,z)= 1+y+z\n\n";
    cout<<"Initial Condition(x0,y0,z0): ";cin>>x>>y>>z;
    cout<<"Final value of x(xn): ";cin>>xn;
    cout<<"No. of steps: ";cin>>n;
    h = (xn-x)/n;
    cout<<left;
    cout<<setprecision(6);
    cout<<setw(10)<<"X"<<setw(10)<<"Y"<<setw(10)<<"Z"<<setw(10)<<"Ynew"<<setw(10)<<"Znew"<<endl;
    for(int i=0;i<=n;i++)
    {

        cout<<setw(10)<<x<<setw(10)<<y<<setw(10)<<z;
        double k1 = h*f(x,y,z);
        double l1 = h*g(x,y,z);
        double k2 = h*f(x+h/2,y+k1/2,z+l1/2);
        double l2 = h*g(x+h/2,y+k1/2,z+l1/2);
        double k3 = h*f(x+h/2,y+k2/2,z+l2/2);
        double l3 = h*g(x+h/2,y+k2/2,z+l2/2);
        double k4 = h*f(x+h,y+k3,z+l3);
        double l4 = h*g(x+h,y+k3,z+l3);
        double k = (k1+2*k2+2*k3+k4)/6;
        double l = (l1+2*l2+2*l3+l4)/6;
        yn = y;
        zn = z;
        y = y+k;
        x = x+h;
        z = z+l;
        cout<<setw(10)<<y<<setw(10)<<z<<endl;
    }
    cout<<"At x = "<<xn<<", y = "<<yn<<", z = "<<zn<<endl;
    return 0;
}
