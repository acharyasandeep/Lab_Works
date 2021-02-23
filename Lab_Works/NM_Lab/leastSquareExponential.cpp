//exponential curve fitting using least square method 
//y=ax^b

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the no. of data: ";
    cin>>n;
    double* X = new double[n];
    double* Y = new double[n];
    cout<<"Enter data for X"<<endl;
    for(int i=0;i<n;i++)
        cin>>X[i];
    cout<<"Enter data for Y"<<endl;
    for(int i=0;i<n;i++)
        cin>>Y[i];

    double sumx,sumx2,sumy,sumxy;
    sumx=sumx2=sumy=sumxy=0;
    for(int i=0;i<n;i++)
    {
        sumx+=log(X[i]);
        sumx2+=log(X[i])*log(X[i]);
        sumy+=log(Y[i]);
        sumxy+=log(X[i])*log(Y[i]);
    }
    double A,a,b;
    b = (n*sumxy-sumx*sumy)/(n*sumx2-sumx*sumx);
    A = (sumy-b*sumx)/n;
    a=exp(A);
    cout<<"The required curve is: y = "<<a<<"*x^"<<b<<endl;
    delete []X;
    delete []Y;
    return 0;
}
