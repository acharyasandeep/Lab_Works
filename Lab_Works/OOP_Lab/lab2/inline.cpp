#include <iostream>
inline double taxcut(double aempsalary)
{
    aempsalary=aempsalary-0.1*aempsalary;
    return aempsalary;
}
int main()
{
    std::cout<<"Enter Your Salary: ";
    double empsalary;
    std::cin>>empsalary;
    empsalary=taxcut(empsalary);
    std::cout<<"Your final Salary after cutting tax is: "<<empsalary<<std::endl;
    return 0;

}
