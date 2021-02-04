#include <iostream>
double incsal(double aempsalary,double aperinc=12)
{
    aempsalary=aempsalary+(aperinc/100)*aempsalary;
    return aempsalary;
}
int main()
{
    std::cout<<"Salary Table in 2009"<<std::endl<<std::endl;
    std::cout<<"Chief executive officer Rs. 35000/m"<<std::endl
             <<"Information officer Rs. 25000/m"<<std::endl
             <<"System analyst Rs. 24000/m"<<std::endl
             <<"Programmer Rs. 18000/m"<<std::endl;
    std::cout<<std::endl<<std::endl;

    std::cout<<"Salary Table in 2010 After Increment"<<std::endl<<std::endl;
    std::cout<<"Chief executive officer Rs. "<<incsal(35000,9)<<"/m"<<std::endl
             <<"Information officer Rs. "<<incsal(25000,10)<<"/m"<<std::endl
             <<"System analyst Rs. "<<incsal(24000)<<"/m"<<std::endl
             <<"Programmer Rs. "<<incsal(18000)<<"/m"<<std::endl;
    return 0;
/*Chief executive officer Rs. 35000/m




*/
}
