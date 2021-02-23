#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
double f(vector<double> &coeff, double x)
{
    double sum=0;
    for(int i=0;i<coeff.size();i++)
    {
        sum+=coeff.at(i)*pow(x,coeff.size()-i-1);
    }
    return sum;
}
double df(vector<double>&coeff, double x)
{
    double sum=0;
    for(int i=0;i<coeff.size()-1;i++)
    {
        sum+=coeff.at(i)*(coeff.size()-i-1)*pow(x,coeff.size()-i-2);
    }
    return sum;
}
int main()
{
    double x,e;
    int deg;
    cout<<"Enter the degree of equation: ";cin>>deg;
    vector<double> coeff(deg+1);
    cout<<"Enter the coefficients:(ax^n+bx^n-1+...+c) ";
    for(int i=0;i<coeff.size();i++)
    {
        cin>>coeff.at(i);
    }
    cout<<"Enter initial value x0: ";cin>>x;
    cout<<"Enter error tolerance: ";cin>>e;
    double step=1;
    double nextx;
    do
    {
        nextx=x-f(coeff,x)/df(coeff,x);
        x=nextx;
        cout<<"Step "<<step<<": X = "<<x<<endl;
        step++;
    }
    while(abs(f(coeff, x))>e);
    cout<<"X = "<<nextx<<endl;
    return 0;
}
