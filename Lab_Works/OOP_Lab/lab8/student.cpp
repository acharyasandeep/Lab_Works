#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
struct Student
{
    char name[20];
    int student_id;
    char department[20];
    char address[30];
};
ostream & operator <<(ostream &out,Student &s1)
{
    out<<"Name: "<<s1.name<<endl;
    out<<"Student Id: "<<s1.student_id<<endl;
    out<<"Department: "<<s1.department<<endl;
    out<<"Address: "<<s1.address<<endl;
}
int main()
{
    Student s1;
    strcpy(s1.name, "Sandeep");
    s1.student_id = 1;
    strcpy(s1.department,"BCT");
    strcpy(s1.address, "New Baneshwor,Kathmandu");
    fstream file;
    file.open("Student.dat", ios::in | ios::out | ios::binary);
    if ( !file.is_open() ) {
       file.clear();
       file.open("Student.dat", ios::out | ios::binary );
       file.close();
       file.open("Student.dat", ios::in | ios::out | ios::binary);
    }
     if(file.is_open())
    {
        cout<<"nice";
    }
    file.write((char*)(&s1),sizeof(Student));
    Student s2;
    file.seekg(0);
    file.read((char*)(&s2),sizeof(Student));
    cout<<s2;
    if(file.fail())
    {
        cout<<"Cannot create file";
    }
    file.close();

}
