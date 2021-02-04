#include <iostream>
using namespace std;
int fibo(int n,int a=0,int b=1)
{
    if(n==0)
        return a;
    else if(n==1)
        return b;
    else
        return fibo(n-1,b,a+b);   
}
int main()
{
    int n;
    cout<<"Find nth fibonacci: ";cin>>n;
    cout<<"fibonacci("<<n<<") = "<<fibo(n);
    return 0;
}