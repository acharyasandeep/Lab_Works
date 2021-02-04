#include <iostream>
#include <cstring>
#include <typeinfo>
using namespace std;
class Vehicle
{
protected :
    string vec_name;
    int no_of_wheels;
public:
    Vehicle(string name, int wheels)
    {
        vec_name=name;
        no_of_wheels=wheels;
    }
    void display()
    {
        cout<<"From Vehicle:"<<endl;
        cout<<"name ="<<vec_name<<endl<<"no of wheels="<<no_of_wheels<<endl<<endl;
    }
};
class Bus:public Vehicle
{
    int bus_id;
public:
    Bus (string name, int wheels,int id):Vehicle(name,wheels)
    {
        bus_id=id;
    }
    void display()
    {
        cout<<"From Bus:"<<endl;
        cout<<"name ="<<vec_name<<endl<<"no of wheels="<<no_of_wheels<<endl<<"bus id ="<<bus_id<<endl<<endl;
    }
};
class Car:public Vehicle
{
    int car_id;
public:
    Car (string name, int wheels,int id):Vehicle(name,wheels)
    {
        car_id=id;
    }
    void display()
    {
        cout<<"From Car:"<<endl;
        cout<<"name ="<<vec_name<<endl<<"no of wheels="<<no_of_wheels<<endl<<"car id ="<<car_id<<endl<<endl;
    }
};
class Bike:public Vehicle
{
    int bike_id;
public:
    Bike (string name, int wheels,int id):Vehicle(name,wheels)
    {
        bike_id=id;
    }
    void display()
    {
        cout<<"From Bike:"<<endl;
        cout<<"name ="<<vec_name<<endl<<"no of wheels="<<no_of_wheels<<endl<<"bike id ="<<bike_id<<endl<<endl;
    }
};
int main()
{
    Vehicle *v;
    Car *car = new Car("Tesla",4,342);
    cout<<"Before type casting:"<<endl;
    car->display();

    v=dynamic_cast<Vehicle *>(car);
    cout<<"After type casting:"<<endl;
    v->display();
    cout<<"Type ID:"<<endl;
    cout<<typeid(*car).name()<<endl;
    cout<<typeid(*v).name()<<endl;
}

