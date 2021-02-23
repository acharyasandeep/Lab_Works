//A program to find the best fit curve of the form: y = a + bx for the 
//given n no of data using method of least squares 

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the no of data: ";cin>>n;
    double *x=new double[n]; //datas for x
    double *y=new double[n]; //datas for y
    cout<<"Enter data for x: "<<endl;
    for(int i=0;i<n;i++)
        cin>>x[i];

    cout<<endl<<"Enter data for y: "<<endl;
    for(int i=0;i<n;i++)
        cin>>y[i];

    double sumx,sumy,sumxy,sumx2;
    sumx=sumy=sumxy=sumx2=0;
    for(int i=0;i<n;i++)
    {
        //calculation of required sums
        sumx+=x[i];
        sumy+=y[i];
        sumxy+=x[i]*y[i];
        sumx2+=pow(x[i],2);
    }
    double a,b;
    a = b = 0;

    //calculating a and  b after solving two normal equations
    //for y  = a + bx
    //1. sumy = na +  bsumx
    //2. sumxy = asumx + bsumx2

    b = (n*sumxy - sumx*sumy)/(n*sumx2 - sumx*sumx);
    a = (sumy-b*sumx)/n;

    //display best fit curve

    cout<<endl<<"Curve of the best fit is: y = "<<a<<" + "<<b<<"x"<<endl;
    
    //free memory
    delete []x;
    delete []y;

    return 0;
}
