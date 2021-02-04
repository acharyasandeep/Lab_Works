#include <iostream>
class carPark
{
    int carId;
    int chargePerHour;
    float time;
public:
    void setData();
    void showData();
};

void callFunct()
{
    carPark car1;
    car1.setData();
    car1.showData();
}

void carPark::setData()
{
    std::cout<<"Enter CarId: ";
    std::cin>>carId;
    std::cout<<"Enter Charge/Hour: ";
    std::cin>>chargePerHour;
    std::cout<<"Enter parking time: ";
    std::cin>>time;
    std::cout<<"\n";
}

void carPark::showData()
{
    std::cout<<"Car Parking Information\n\n";
    std::cout<<"CarId: "<<carId;
    std::cout<<"\nParking Hours: "<<time;
    std::cout<<"\nCharges: "<<chargePerHour*time;
    std::cout<<"\n";
}

int main()
{
    callFunct();
    return 0;
}

