#include <iostream>
using namespace std;
long long factorial(long long n,long long res=1)
{
    if (n<=0)
        return res;
    return factorial(n-1,n*res);
}
/* long long fact(long long n)
{
    return factorial(1,n);
} */
int main()
{
    long long n;
    cout<<"Enter the number: ";cin>>n;
    cout<<n<<"! = "<<factorial(n);
    return 0;
}