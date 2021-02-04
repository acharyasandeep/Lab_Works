#include <iostream>
using std::cout;
using std::cin;
using std::endl;

double & settemp(double & temp1, double & temp2)
{
    if(temp1>temp2)
        return temp1;
    else
        return temp2;
}

int main()
{
    double temp1,temp2;
    cout<<"Enter two temperatures: ";
    cin>>temp1>>temp2;
    cout<<"The largest temp is: "<<settemp(temp1,temp2)<<endl;
    cout<<"Setting largest temp to 100 using return by refrence"<<endl;
    settemp(temp1,temp2)=100;
    cout<<"Temp1 = "<<temp1<<endl;
    cout<<"Temp2 = "<<temp2<<endl;
}
