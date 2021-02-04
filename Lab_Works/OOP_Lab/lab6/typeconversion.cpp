#include <iostream>
class distance
{
private:
    int meter;
    float centimeter;
public:
    distance() {}
    distance(float ameter, float acentimeter)
    {
        meter = ameter;
        centimeter = acentimeter;
    }

    distance(float ameter)
    {
        meter = static_cast<int>(ameter);
        centimeter=(ameter - meter)*100;
    }

    operator float () const
    {
        float m;
        m = meter + centimeter/100;
        return (m);
    }

    void display()
    {
        std::cout<<"Meter = "<<meter<<std::endl;
        std::cout<<"Centimeter = "<<centimeter<<std::endl;
    }

};
int main()
{
    distance d1(4.5);
    distance d2(3,4);
    std::cout<<"For D1\n";
    d1.display();
    std::cout<<"For D2\n";
    d2.display();

    std::cout<<"After type cast\n";

    std::cout<<"D1 = "<<d1<<std::endl;
    std::cout<<"D2 = "<<d2<<std::endl;
    return 0;
}
