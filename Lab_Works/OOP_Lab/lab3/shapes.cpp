#include <iostream>
#include <cmath>
class circle
{
private:
    double radius;
    const double pie=3.14;
public:
    void getdata()
    {
        std::cout<<"Enter radius: ";
        std::cin>>radius;
    }
    double circumference()
    {
        return 2*pie*radius;
    }
    double area()
    {
        return pie*radius*radius;
    }
    void display()
    {
        std::cout<<"Radius: "<<radius<<"\n";
        std::cout<<"Circumference: "<<circumference()<<"\n";
        std::cout<<"Area: "<<area()<<"\n";
    }
};
class triangle
{
private:
    double side1,side2,side3;
public:
    bool getdata()
    {
        std::cout<<"Enter three sides of triangle: ";
        std::cin>>side1>>side2>>side3;
        if((side1>=side2+side3)||(side2>=side1+side3)||(side3>=side1+side2))
        {
            std::cout<<"Not a valid triangle."<<"\n"
                     <<"Sum of two sides must always be greater than the third side."<<"\n";
            return false;
        }
        else
            return true;
    }
    double perimeter()
    {
        return side1+side2+side3;
    }
    double area()
    {
        double s=perimeter()/2;
        return sqrt(s*(s-side1)*(s-side2)*(s-side3));
    }
    void display()
    {
        std::cout<<"Sides : "<<side1<<", "<<side2<<", "<<side3<<"\n";
        std::cout<<"Perimeter : "<<perimeter()<<"\n";
        std::cout<<"Area : "<<area()<<"\n";
    }
};
class rectangle
{
private:
    double side1,side2;
public:
    void getdata()
    {
        std::cout<<"Enter sides of Rectangle: ";
        std::cin>>side1>>side2;
    }
    double perimeter()
    {
        return 2*(side1+side2);
    }
    double area()
    {
        return side1*side2;
    }
    void display()
    {
        std::cout<<"Sides : "<<side1<<", "<<side2<<"\n";
        std::cout<<"Perimeter: "<<perimeter()<<"\n";
        std::cout<<"Area: "<<area()<<"\n";
    }
};

int main()
{
    circle c1;
    c1.getdata();
    c1.display();
    triangle t1;

    if(t1.getdata())
        t1.display();

    rectangle r1;
    r1.getdata();
    r1.display();

}
