#include <bits/stdc++.h>
using namespace std;
void swap(int &a, int &b)
{
	int temp = a;
	a=b;
	b=temp;
}
void reverse(vector<int>&v1)
{
	int low=0;
	int high=v1.size()-1;
	while(low<high)
	{
		swap(v1.at(low),v1.at(high));
		low++;
		high--;
	}
}
void printSubsets(vector<vector<int>> &v1)
{
	for(int i=0;i<v1.size();i++)
	{
		cout<<"{";
		for(int j=0;j<v1.at(i).size();j++)
		{
			cout<<v1.at(i).at(j);
			if(j!=v1.at(i).size()-1)
				cout<<", ";
		}
		cout<<"}"<<endl;
	}

}
void print(vector<int> &v1)
{
	cout<<"{";
	for(int i=0;i<v1.size();i++)
	{
		cout<<v1.at(i);
		if(i!=v1.size()-1)
			cout<<", ";
	}
	cout<<"}"<<endl;

}
int main()
{
	vector<int> set{1,2,3,4,5};
	vector<vector<int>> subsets;
	vector<int> subset;
	vector<int> vec;
	subsets.push_back(subset);
	for(int i=1;i<pow(2,set.size());i++)
	{
		int x=i; //x is temp variable to calculate the binary representation of i
		while(x>0)
		{
			int rem = x%2;
			vec.push_back(rem);
			x = x/2;
		}
		int p = set.size()-vec.size(); //p to make binary digits same in all i
		for(int j=0;j<p;j++)
		{
			vec.push_back(0); //now 1 is represented by 10000. so we have to reverse it
		}
		reverse(vec); //i correct binary form 00001
		print(vec);
		for(int j=0;j<vec.size();j++)
		{
			if(vec.at(j)==1)
			{
				subset.push_back(set.at(j));
			}
		}
		subsets.push_back(subset);
		subset.clear();
		vec.clear();
	}
	cout<<"Given set is: ";
	print(set);
	cout<<"The subsets are as follows: "<<endl;
	printSubsets(subsets);
}
