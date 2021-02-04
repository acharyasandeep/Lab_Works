#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
	int num;
	cout<<"Prime numbers upto: ";cin>>num;
	vector<int> v1(num+1);
	for(int i=0;i<=num;i++)
		v1.at(i) = 1;
	v1[0]=0;
	v1[1]=0;
	for(int i=2;i<=sqrt(num);i++)
		if(v1[i]==1)
			for(int j=i*i;j<=num;j+=i)
				v1[j]=0;
	cout<<"Here you go, ";
	for(int i=0;i<=num;i++)
	{
		if(v1[i]==1)
			cout<<i<<" ";
	}
}

