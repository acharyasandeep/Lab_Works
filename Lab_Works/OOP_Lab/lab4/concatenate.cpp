#include <iostream>
class mystring
{
    char *str;
    int length;
public:
    mystring(){}
    mystring(const char *gstring)
    {
        int i=0;
        for(i=0;gstring[i]!='\0';i++) {}
        length=i;
        str = new char[length+1];
        for(i=0;i<length;i++)
        {
            str[i]=gstring[i];
        }
    }
    void join(const mystring &str1, const mystring &str2)
    {
        length=(str1.length + str2.length);
        str = new char[length + 1];

        for(int i=0;i<str1.length;i++)
        {
            str[i]=str1.str[i];
        }

        for(int i=str1.length;i<length;i++)
        {
            str[i]=str2.str[i-str1.length];
        }
        str[length]='\0';
    }

    void display()
    {
        std::cout<<str;
    }

    ~mystring()
    {
        delete []str;
    }

};
int main()
{
    mystring string1("Engineers are");
    mystring string2(" creatures of logic.");
    mystring string3;
    string3.join(string1,string2);
    string3.display();
}
