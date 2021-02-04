#include <iostream>
#include <cstdlib>
class celsius{
    double celsius;
    double toFahren()
    {
        return ((9*celsius/5)+32);
    }
public:
    void getdata()
    {
        std::cout<<"Temperature in Celsius: ";
        std::cin>>celsius;
    }
    void display()
    {
        std::cout<<"Temperature in Fahrenheit: "<<toFahren();
    }
};
class fahren{
    double fahrenheit;
    double toCelsius()
    {
        return (5*(fahrenheit-32)/9);
    }
public:
    void getdata();
    void display();
};

void fahren::getdata()
{
    std::cout<<"Temperature in Fahrenheit:  ";
    std::cin>>fahrenheit;
}
void fahren::display()
{
    std::cout<<"Temperature in Celsius: "<<toCelsius();
}
int main()
{
    char check;
    do
    {
        system("cls");
        celsius c1;
        fahren f1;
        c1.getdata();
        c1.display();
        std::cout<<std::endl<<std::endl;
        f1.getdata();
        f1.display();
        std::cout<<"\n\nYou want another conversion('y' | 'Y' for yes: ";
        std::cin>>check;
        std::cout<<std::endl;
    }
    while ((check=='y' )||(check=='Y'));
}
