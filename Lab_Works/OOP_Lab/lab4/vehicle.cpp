#include <iostream>
class vehicle
{
private:
    int num_vehicle;
    float rate,hour,total_charge;
public:
    vehicle(int anum_vehicle, float ahour, float arate )
    :num_vehicle(anum_vehicle),hour(ahour),rate(arate){}
    vehicle(vehicle &v1)
    {
        num_vehicle = v1.num_vehicle;
        hour = v1.hour;
        rate = v1.rate;
    }
    float cal_charge()
    {
        total_charge = num_vehicle * rate * hour;
        if(num_vehicle >= 10)
        {
            std::cout<<"\nBefore Discount: "<<total_charge<<"\n";
            total_charge -= 0.1 * total_charge;
        }
        return total_charge;

    }
    void display()
    {
        std::cout<<"No. of Vehicles: "<<num_vehicle<<"\n";
        std::cout<<"Hours of parking: "<<hour<<"\n";
        std::cout<<"Rate(1 vehicle for an hour): "<<rate<<"\n";
        std::cout<<"Total charge: "<<cal_charge()<<"\n";
    }
};
int main()
{
    int vehicle_num;
    float hour, rate;
    std::cout<<"Enter the no of vehicles, hours, rate: ";
    std::cin>>vehicle_num>>hour>>rate;
    vehicle v1(vehicle_num, hour, rate);
    vehicle v2(v1);
    v2.display();
}
