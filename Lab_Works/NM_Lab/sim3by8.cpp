//integration of a function using simpson's 3/8 rule
//
#include <iostream>
#include <cmath>
using namespace std;
double f(double x)
{
    return sin(x) - log(x) + exp(x); 
}
int main()
{
    double a,b,h,n;
    cout<<"For the function: sin(x) - ln(x) + e^x\n\n";
    cout<<"Limits of integration\nLower Limit: ";cin>>a;
    cout<<"Upper Limit: ";cin>>b;
    cout<<"No. of strips: ";cin>>n;
    h = (b-a)/n;
    double result = f(a)+f(b);
    for(int i=1;i<n;i++)
    {
        double k = a + h*i;
        if(i%3==0)
            result += 2*f(k);
        else
            result += 3*f(k);
    }
    result = (3*h/8)*result;
    cout<<"Result = "<<result<<endl;
    return 0;
}
