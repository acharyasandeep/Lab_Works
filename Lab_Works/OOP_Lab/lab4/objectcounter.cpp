#include <iostream>
class objcount
{
private:
    static int count;
public:
    objcount()
    {
        count++;
        std::cout<<"Object no: "<<count<<std::endl;
    }

};
int objcount::count = 0;
int main()
{
    objcount ob1;
    objcount ob2;
}
