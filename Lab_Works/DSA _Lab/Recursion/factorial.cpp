#include <iostream>
using namespace std;
long long factorial(long long n)
{
    if(n<3 && n>=0)
        return n;

    return n*factorial(n-1);
}
int main()
{
    int n;
    cout<<"Enter a number to find Factorial: ";cin>>n;
    cout<<n<<"! = "<<factorial(n);
    return 0;
}