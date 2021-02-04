#include <iostream>
using std::cout;
using std::cin;
using std::endl;
struct date{
int years;
int months;
int days;
};
int main()
{
    date d1;
    cout<<"Enter the date: ";
    cin>>d1.years>>d1.months>>d1.days;
    if((d1.months <= 12) &&(d1.days<=30))
    {
        cout<<endl<<"Date (yy/mm/dd): "<<d1.years<<"/"<<d1.months<<"/"<<d1.days<<endl;
    }
    else{
        cout<<"Invalid date"<<endl;
    }

}
