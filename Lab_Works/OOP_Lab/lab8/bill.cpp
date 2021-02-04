#include <iostream>
using namespace std;
int main()
{
    int items[4]={10,8,12,15};
    double cost[4]={75.777,100.123,60.453,99.908};
    cout.width(5);
    cout<<"ITEMS";
    cout.width(10);
    cout<<"COST";
    cout.width(15);
    cout<<"TOTAL VALUE"<<endl;
    double sum =0;
    for(int i=0;i<4;i++)
    {
        cout.width(5);
        cout<<items[i];
        cout.width(10);
        cout<<cost[i];
        cout.width(15);
        double value = items[i]*cost[i];
        cout<<value<<"\n";
        sum +=value;

    }
    cout<<"\nGrand Total = ";
    cout.width(2);
    cout.precision(2);
    cout.setf(ios::fixed);
    cout<<sum<<"\n";
    return 0;
}
