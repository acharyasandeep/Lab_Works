//a program to show function overloading
//feets to inches
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
int feettoinch(int feet,int inchesperfeet=12);
float feettoinch(float &ft);
float feettoinch();
int main()
{
    float feet;
    int ft;
    cout<<"Calling no argument function"<<endl;
    feettoinch();
    cout<<"Call by refrence"<<endl<<"Enter feets as float: ";
    cin>>feet;
    cout<<"Inches: "<<feettoinch(feet)<<endl;
    cout<<"Calling function having default args and feet value as int"<<endl<<"Enter feets as integer: ";
    cin>>ft;
    cout<<"Inches: "<<feettoinch(ft)<<endl;

}
int feettoinch(int feet, int inchesperfeet)
{
    int inches=0;
    inches=feet*inchesperfeet;
    return inches;
}

float feettoinch(){
    int feet=5;
    cout<<"Feet = "<<feet<<endl;
    cout<<"Inches = "<<feet*12<<endl;
}
float feettoinch(float &ft)
{
    float inches =0;
    inches=ft*12;
    return inches;
}
