#include <bits/stdc++.h>
using namespace std;
void print(vector<int> &v1)
{
	for(int i=0;i<v1.size();i++)
		cout<<v1.at(i);
	cout<<endl;
}
int main()
{
	int num;
	cout<<"Enter the number: ";cin>>num;
	vector<int>v1(32, 0);
	int index = v1.size()-1;
	while(index!=0)
	{
		v1.at(index) = 1 & num;
		index--;
		num = num >> 1;
	}
	print(v1);
}

