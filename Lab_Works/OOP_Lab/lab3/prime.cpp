#include <iostream>
#include <cstdlib>
using std::cout;
using std::cin;
using std::endl;
class number{
    int num;
    bool isPrime;
public:
    void getdata()
    {
        cout<<"Number to check prime or not: ";
        cin>>num;
    }
    bool checkPrime()
    {
        if(num<2)
            return false;
        else
        {
            isPrime=true;
            for(int i=2;i<num;i++)
            {
                if(num%i==0)
                {
                    isPrime=false;
                    cout<<"Divisible by: "<<i<<endl;
                    break;
                }
            }
            return isPrime;
         }
    }
    void display()
    {
        if(checkPrime())
        {
            cout<<"Yes, "<<num<<" is a prime number."<<endl;
        }
        else
        {
            cout<<"No, "<<num<<" is not a prime number."<<endl;
        }
    }
};
int main()
{
    number n1;
    char ch;
    while(1)
    {
        n1.getdata();
        n1.display();
        cout<<"\nWanna check another one?('y' for yes)"<<endl;
        cin>>ch;
        if((ch!='y')&&(ch!='Y'))
            break;
        system("cls");
    }
}
