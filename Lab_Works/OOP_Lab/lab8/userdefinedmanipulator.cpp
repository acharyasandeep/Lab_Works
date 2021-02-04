#include <iostream>
using namespace std;
ostream & currency(ostream & output)
{
    output.setf(ios::showpos);
    output.setf(ios::fixed);
    output.precision(2);
    output<<"Rs. ";
    return output;
}
int main()
{
    double money;
    cout<<"Enter the Money you have: ";cin>>money;
    cout<<currency<<money<<endl;
}
