//trapezoidal rule: I = (1/2)*h[(y0 + yn) + 2(y1 + y2 + ... + y(n-1))]
//n is the no of data , h is the step size, y = f(x)

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    double a,b,h,n; //upper limit, lower limit, step size,no of strips
    cout<<"Enter the lower limit: ";cin>>a;
    cout<<"Enter the upper limit: ";cin>>b;
    cout<<"Enter the no of strips: ";cin>>n;
    h = (b-a)/n;
    vector<double> Y(n+1,0);
    cout<<"Enter data for Y\n";
    for(int i=0;i<=n;i++)
        cin>>Y.at(i);
    double sum = Y.at(0)+Y.at(n);
    for(int i=1;i<n;i++)
        sum+=2*Y.at(i);
    sum = sum*(h/2);
    cout<<"Result = "<<sum<<endl;
    return 0;
}
