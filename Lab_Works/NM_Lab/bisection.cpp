#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double function(double x)
{
    //return 8*pow(x,2)-64*x*log2(x);
    //return pow(x,3)-4*x-9;
    return sin(x)-1/x;
}
int main()
{
    cout<<"Given function is: sin(x)-1/x"<<endl;
    double a,b,e;//(a,b) initial value, e= tolerance error
    cout<<"Enter initial values(a,b): ";
    cin>>a>>b;
    if(function(a)*function(b)>0)
    {
        cout<<"Please choose suitable interval such that: f(a)*f(b)<0"<<endl;
        return -1;
    }
    cout<<"Enter error tolerance: ";
    cin>>e;
    double c;
    int count=1;
    //For tabular view uncomment the code containing setw and width and comment the current output code
    //const int width=15;
    //cout<<left;
    //cout<<setw(width)<<"a"<<setw(width)<<"b"<<setw(width)<<"c"<<setw(width)<<"f(a)"<<setw(width)<<"f(b)"<<setw(width)<<"f(c)"<<endl<<endl;
    do
    {
        c=(a+b)/2;
        //cout<<setprecision(6)<<setw(width)<<a<<setw(width)<<b<<setw(width)<<c<<setw(width)<<function(a)<<setw(width)<<function(b)<<setw(width)<<function(c)<<endl;
        cout<<"Iteration "<<count<<": X = "<<c<<endl;
        if(function(c)*function(a)>0)
            a=c;
        else
            b=c;

        count++;

    }
    while(abs(function(c))>e);
    cout<<endl;
    cout<<"x = "<<c<<endl;

}
