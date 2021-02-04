#include <iostream>
#include <cstring>
#include <limits>
class musician
{
private:
    char stringarr[5][10];
    char windarr[5][15];
    char precarr[5][15];
public:
    void String()
    {
        strcpy(stringarr[0],"veena");
        strcpy(stringarr[1],"guitar");
        strcpy(stringarr[2],"sitar");
        strcpy(stringarr[3],"sarod");
        strcpy(stringarr[4],"mandolin");
        std::cout<<"Showing from string() function\n\n";
        for(int i=0;i<5;i++)
        {
            std::cout<<stringarr[i]<<"\n";
        }
    }
    void Wind()
    {
        strcpy(windarr[0],"flute");
        strcpy(windarr[1],"clarinet");
        strcpy(windarr[2],"saxophone");
        strcpy(windarr[3],"nadhaswaram");
        strcpy(windarr[4],"piccolo");
        std::cout<<"Showing from wind() function\n\n";
        for(int i=0;i<5;i++)
        {

            std::cout<<windarr[i]<<"\n";
        }
    }
    void Prec()
    {
        strcpy(precarr[0],"tabla");
        strcpy(precarr[1],"mridangam");
        strcpy(precarr[2],"bangos");
        strcpy(precarr[3],"drums");
        strcpy(precarr[4],"tambour");
        std::cout<<"Showing from prec() function\n\n";
        for(int i=0;i<5;i++)
        {

            std::cout<<precarr[i]<<"\n";
        }
    }
};

class TypeIns : public musician
{
private:
    void get()
    {
        using std::cout;
        cout<<"Type of Instruments to be displayed\n\n";
        cout<<"a. String instruments\n";
        cout<<"b. Wind instruments\n";
        cout<<"c. Percussion instruments\n";
    }
public:
    void show()
    {
        get();
        char c;

        while(true)
        {
            std::cout<<"\nEnter any of the above choices(a/b/c) or n to exit: ";
            std::cin>>c;
            if(c=='n')
                break;
            std::cout<<"\n\n";
            switch(c)
            {

            case 'a':
                String();
                break;
            case  'b':
                Wind();
                break;
            case 'c':
                Prec();
                break;
            default:
                std::cout<<"Wrong Choice, Try again";
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');


        }
    }
};

int main()
{
    TypeIns t1;
    t1.show();
}




