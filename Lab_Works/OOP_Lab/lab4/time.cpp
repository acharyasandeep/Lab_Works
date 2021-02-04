#include<iostream>
using namespace std;
class time
{
private:
    unsigned int h,m,s;
public:
    time()
    {
        h=0;
        m=0;
        s=0;
    }
    time(unsigned int dh,unsigned int dm, unsigned int ds)
    {
        if(dh<24)
            h=dh;
        else
        {
            cerr<<"Error : Hour must be between 0 to 23."<<endl;
        }

        if(dm<60)
            m=dm;
        else
        {cerr<<"Error : Minutes must be between 0 to 60."<<endl;}



        if(ds<60)
            s=ds;
        else
        {
            cerr<<"Error : seconds must be between 0 to 60."<<endl;
        }
    }
    time add_time(time t1,time t2)
    {
        t1.s=t1.s+t2.s;
        if(t1.s>=60)
        {
            t1.m+=t1.s/60;
            t1.s=t1.s-60;
        }
        t1.m=t1.m+t2.m;
        if(t1.m>=60)
        {
            t1.h+=t1.m/60;
            t1.m=t1.m-60;
        }
        t1.h=t1.h+t2.h;
        if(t1.h>=24)
        {
            t1.h%=24;
        }
        return t1;
    }
    void display()
    {
        if((h < 24) && (m < 60) && (s < 60))
            cout<<"Time = "<<h<<':'<<m<<':'<<s<<endl;
        else
        {
            cout<<"Please check your code."<<endl;
        }
    }
};
int main()
{
    time t1(23,43,15),t2(7,19,54),res;
    t1.display();
    t2.display();
    cout<<endl<<"Result of Adding above times"<<endl<<endl;
    res=res.add_time(t1,t2);
    res.display();

}


