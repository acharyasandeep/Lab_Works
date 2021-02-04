#include <iostream>

class coords;
class display;
class operations
{
public:
    coords add(coords, coords);
    coords subtract(coords, coords);
    coords multiply(coords, coords);
    coords divide(coords, coords);
};

class coords
{
private:
    double x;
    double y;
public:
    coords (double ax=0, double ay=0)
    {
        x=ax;
        y=ay;
    }

    friend coords operations::add(coords, coords);
    friend coords operations::subtract(coords, coords);
    friend coords operations::multiply(coords, coords);
    friend coords operations::divide(coords, coords);
    friend class display;
};

coords operations::add(coords c1, coords c2)
{
        coords c3;
        c3.x = c1.x + c2.x;
        c3.y = c1.y + c2.y;
        return c3;
}
coords operations::subtract(coords c1, coords c2)
{
        coords c3;
        c3.x = c1.x - c2.x;
        c3.y = c1.y - c2.y;
        return c3;
}
coords operations::multiply(coords c1, coords c2)
{
        coords c3;
        c3.x = c1.x * c2.x;
        c3.y = c1.y * c2.y;
        return c3;
}
coords operations::divide(coords c1, coords c2)
{
        coords c3;
        c3.x = c1.x / c2.x;
        c3.y = c1.y / c2.y;
        return c3;
}
class display
{
    public:
    void printcoords(coords c3)
    {
        std::cout<<"The coordinates are: ("<<c3.x<<", "<<c3.y<<")\n";
    }

};

int main()
{
    coords c1(2,3);
    coords c2(5,4);
    operations op1;
    display d1;
    d1.printcoords(c1);
    coords c3;
    d1.printcoords(c2);
    std::cout<<"\n      AFTER ADDITION\n\n";
    c3 = op1.add(c1,c2);
    d1.printcoords(c3);
    std::cout<<"\n      AFTER SUBTRACTION\n\n";
    c3 = op1.subtract(c1,c2);
    d1.printcoords(c3);
    std::cout<<"\n      AFTER MULTIPLICATION\n\n";
    c3 = op1.multiply(c1,c2);
    d1.printcoords(c3);
    std::cout<<"\n      AFTER DIVISON\n\n";
    c3 = op1.divide(c1,c2);
    d1.printcoords(c3);

}

