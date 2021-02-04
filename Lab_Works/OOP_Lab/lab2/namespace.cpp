#include <iostream>
using std::cout;
using std::cin;
using std::endl;
namespace square{
    int num;
    int fun(int anum)
    {
        return anum*anum;
    }
}
namespace cube {
    int num;
    int fun(int anum)
    {
        return anum*anum*anum;
    }
}
int main()
{
    square::num=5;
    cube::num=8;
    cout<<square::num<<" Squared = "<<square::fun(square::num)<<endl;
    cout<<cube::num<<" Cubed = "<<cube::fun(cube::num)<<endl;
    return 0;

}

