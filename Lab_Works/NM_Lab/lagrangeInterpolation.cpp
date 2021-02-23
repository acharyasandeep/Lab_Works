//lagarange interpolation for unequal intervals
//Formula:
//f(x) = (x-x1)(x-x2)...(x-xn)/((x0-x1)(x0-x2)...(x0-xn)) + (x-x0)(x-x2)...(x-xn)/((x1-x0)(x1-x2)...(x1-x0))
//+....+ (x-x0)(x-x1)...(x-xn-1)/((xn-x0)(xn-x1)...(xn-xn-1))

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the no. of data: ";cin>>n;
    double *X = new double[n];
    double *Y = new double[n];
    cout<<"Enter data for X"<<endl;
    for(int i=0;i<n;i++)
        cin>>X[i];
    cout<<"Enter data for Y"<<endl;
    for(int i=0;i<n;i++)
        cin>>Y[i];
    
   double xp,yp,p;
   cout<<"Enter x to find y(x): ";cin>>xp;
   yp=0;

   for(int i=0;i<n;i++)
   {
       p=1;
       for(int j=0;j<n;j++)
       {
           if(i!=j)
               p=p*(xp-X[j])/(X[i]-X[j]);
       }
       yp = yp+p*Y[i];
   }
   cout<<"\nAt x = "<<xp<<", y("<<xp<<") = "<<yp<<endl;
   return 0;
}
