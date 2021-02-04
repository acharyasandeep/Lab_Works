#include <iostream>
class optest
{
private:
    int x;
public:
    optest(int ax=0):x(ax) {}
    int getx(){return x;}
    bool operator==(optest t1)
    {
        if(x == t1.x)
            return true;
        else
            return false;
    }

    bool operator !=(optest t1)
    {
        if (x != t1.x)
            return true;
        else
            return false;
    }

    bool operator >(optest t1)
    {
        if(x > t1.x)
            return true;
        else
            return false;
    }

    bool operator <(optest t1)
    {
        if(x < t1.x)
            return true;
        else
            return false;
    }

     bool operator >=(optest t1)
    {
        if(x >= t1.x)
            return true;
        else
            return false;
    }

     bool operator <=(optest t1)
    {
        if(x <= t1.x)
            return true;
        else
            return false;
    }
};
int main()
{
    optest t1(4), t2(8);
    if (t1 < t2)
    {
        std::cout<<t1.getx() <<" is less than "<<t2.getx();
    }
}
