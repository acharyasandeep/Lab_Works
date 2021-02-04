#include <iostream>
using namespace std;
class Shape
{
public:
    virtual void getData() = 0;
    virtual float Area() = 0;
    virtual void Display()= 0;
    virtual ~Shape ()
    {
        cout<<"Shape Destructor\n";
    }
};

class Rectangle : public Shape
{
    float length, breadth;
     float Area()
    {
        return length*breadth;
    }
public:
    void getData()
    {
        cout<<"Enter length and breadth: "; cin>>length>>breadth;
    }

    void Display()
    {
        cout<<"The Area of rectangle is: "<<Area();
        cout<<"\n";
    }
    ~Rectangle ()
    {
        cout<<"Rectangle Destructor\n";
    }
};
class Circle : public Shape
{
    float radius;
    float Area()
    {
        return 3.1415*radius*radius;
    }
public:
    void getData()
    {
        cout<<"Enter the radius: ";cin>>radius;
    }

    void Display()
    {
        cout<<"The Area of circle is: "<<Area();
        cout<<"\n";
    }
    ~Circle ()
    {
        cout<<"Circle Destructor\n";
    }
};
class Trapezoid : public Shape
{
    float b1, b2, h;
    float Area()
    {
        return (b1+b2)*h/2;
    }
public:
    void getData()
    {
        cout<<"Enter two parallel bases and height of trapezoid: ";cin>>b1>>b2>>h;
    }

     void Display()
    {
        cout<<"The Area of Trapezoid is: "<<Area();
    }
    ~Trapezoid ()
    {
        cout<<"Trapezoid Destructor\n";
    }
};
int main()
{
    Shape* s1;
    Rectangle r1;
    s1 = &r1;
    s1->getData();
    s1->Display();
    Circle c1;
    s1 = &c1;
    s1->getData();
    s1->Display();
    Trapezoid t1;
    s1 = &t1;
    s1 ->getData();
    s1 ->Display();
}
