#include <iostream>
using namespace std;
int gcdRecursive(int a, int b)
{
	return b==0?a:gcdRecursive(b,a%b);


}
int main()
{
	int n1,n2;
	cout<<"Enter two numbers to find GCD(HCF): ";
	while(cin>>n1>>n2)
	{
		cout<<"Result: "<<gcdRecursive(n1,n2)<<endl;
		cout<<"Two numbers again(q to exit): ";
	}
	return 0;

}

