#include <iostream>
using namespace std;
class Student
{
public:
    virtual void getData() =0;
    virtual void display() =0;
};
class Science : public Student
{
    char ch;
public:
    void getData()
    {
        cout<<"Press 'E' For Engineering and 'M' for Medical: "; cin>>ch;
    }
    void display()
    {
        if(ch == 'E')
            cout<<"Get ready to survive.";
        else if(ch == 'M')
            cout<<"Doc. Please check me up for free.";
        else
            cout<<"Wrong input, You becoming nothing";
    }
};
int main()
{
    Student* s1;
    Science sc1;
    s1 = &sc1;
    s1 ->getData();
    s1 ->display();
}
