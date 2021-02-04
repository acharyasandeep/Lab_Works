#include<iostream>
#include<cstring>
using namespace std;
class depart
{
    char depart_id[20];
    char depart_name[20];
    static int c;
    int no;
    public:
    depart(const char * id,const char * name)
    {
        strcpy(depart_id,id);
        strcpy(depart_name,name);
        no=++c;
        cout<<"Object"<<no<<" created"<<endl;

    }
    ~depart()
    {
        cout<<"Object"<<no<<" goes out of scope"<<endl;

    }
};
int depart::c=0;
int main()
{
    depart d1("A35","Computer");
    depart d2("A36","Mechanical");
    depart d3("A37","Architecture");
}

