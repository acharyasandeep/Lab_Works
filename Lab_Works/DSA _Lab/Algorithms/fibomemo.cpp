//fibonacci series with recursion and memoization
#include <iostream>
using namespace std;
int fib(int num,int fibocache[])
{
	if (num<=1)
		return num;
	if(fibocache[num]!=-1)
		return fibocache[num];
	fibocache[num]=fib(num-1,fibocache)+fib(num-2,fibocache);
	return fibocache[num];

}
int main()
{
	int num;
	num = 41;
       	int fibocache[100];
	for(int i=0;i<100;i++)
		fibocache[i]=-1;
	for(int i=0;i<num;i++)
	{


		cout<<i<<" : "<<fib(i,fibocache);
		cout<<endl;

	}

}
