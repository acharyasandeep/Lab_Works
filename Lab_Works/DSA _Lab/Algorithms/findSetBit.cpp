#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int num;
	cout<<"Enter the number to find set bits: ";cin>>num;
	cout<<"The set bits are: ";
	for(int i=1;i<=int(log2(num))+1;i++)
	{
		if(num & 1<<(i-1))
		{
			cout<<i<<" ";
		}
			
	}

}
