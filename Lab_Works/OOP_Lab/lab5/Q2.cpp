#include <iostream>
class coordinates
{
private:
    double x,y,z;
public:
    coordinates(double ax=0, double ay=0, double az=0)
    {
        x=ax;
        y=ay;
        z=az;
    }
    void display()
    {
        std::cout<<"Coordinates: ("<<x<<", "<<y<<", "<<z<<")\n";
    }

    friend coordinates operator+(coordinates c1, coordinates c2);
    friend coordinates operator-(coordinates c1, coordinates c2);

};
coordinates operator+(coordinates c1, coordinates c2)
{
    coordinates c3;
    c3.x = c1.x + c2.x;
    c3.y = c1.y + c2.y;
    c3.z = c1.z + c2.z;
    return c3;
}
coordinates operator-(coordinates c1, coordinates c2)
{
    coordinates c3;
    c3.x = c1.x - c2.x;
    c3.y = c1.y - c2.y;
    c3.z = c1.z - c2.z;
    return c3;
}
int main()
{
    coordinates c1(4,5,6);
    coordinates c2(1,5,8);
    coordinates c3;
    c3 = c1 + c2;
    std::cout<<"\n      AFTER ADDITION\n\n";
    c3.display();
    c3 = c1 - c2;
    std::cout<<"\n      AFTER SUBTRACTION\n\n";
    c3.display();
    return 0;
}
