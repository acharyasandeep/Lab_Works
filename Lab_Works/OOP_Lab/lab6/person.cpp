#include <iostream>
class Person
{
private:
    char name[20];
    int age;
public:
    void getData()
    {
        std::cout<<"\nEnter Name: "; std::cin.getline(name,20);
        std::cout<<"\nEnter Age: "; std::cin>>age;
    }
    void printAddress()
    {
        std::cout<<"\nPerson has an address "<<this<<"\n";
    }
    void setName()
    {
        std::cout<<"\nSet new Name: ";
        std::cin.get();
        std::cin.getline(name,20);
    }
     void showData()
    {

        std::cout<<"\nName: "<<name;
        std::cout<<"\nAge: "<<age;
    }

};

class Student : public Person
{
private:
    int rollNo;
public:
    void getData()
    {
        Person::getData();
        std::cout<<"\nEnter Rollno: ";  std::cin>>rollNo;
    }

    void printAddress()
    {
        std::cout<<"\nStudent's address: "<<this;
    }
    void setRollno()
    {
        std::cout<<"Set new Rollno: "; std::cin>>rollNo;
    }
    void showData()
    {
        Person::showData();
        std::cout<<"\nRollno: "<<rollNo;
    }

} ;

class Employee : public Person
{
private:
    int empId;
    char post[20];
public:

    void getData()
    {
        Person::getData();
        std::cout<<"\nEnter Employee Id: "; std::cin>>empId;
        std::cout<<"\nEnter your post: "; std::cin.getline(post,20);
    }
    void printAddress()
    {
        std::cout<<"\nEmployee's address: "<<this;
    }

};

int main()
{
    Person p1,p2;
    p1.printAddress();
    Student s1;
    s1.printAddress();
    Employee e;
    e.printAddress();
    s1.getData();
//    s1.Person::showData();
    s1.showData();
    s1.setName();
    s1.setRollno();
//    s1.Person::showData();
    s1.showData();
}
