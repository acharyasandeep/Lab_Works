//gcd using euclidean algorithm
#include <iostream>
using namespace std;
int gcd(int a, int b)
{
	int dividend = a;
	int divisor = b;
	while(divisor !=0 )
	{
		int remainder = dividend % divisor;
		dividend = divisor;
		divisor = remainder;
	}
	return dividend;
}
int main()
{
	int n1,n2;
	cout<<"Enter two numbers to find GCD(HCF): ";
	while(cin>>n1>>n2)
	{
		cout<<"Result: "<<gcd(n1,n2)<<endl;
		cout<<"Two numbers again(q to exit): ";
	}
	return 0;

}
