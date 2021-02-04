#include <bits/stdc++.h>
using namespace std;
int maxPairProduct(int *arr, int size)
{
	int maxIndex1=-1;
	for(int i=0;i<size/2;i++)
	{
		if((maxIndex1 == -1)||(arr[i]>arr[maxIndex1]))
			maxIndex1=i;

	}
	int maxIndex2=-1;
	for(int i=size/2;i<size;i++)
	{
		if((maxIndex2==-1) || (arr[i]>arr[maxIndex2]))
			maxIndex2=i;
	}
	if(arr[maxIndex1]>arr[maxIndex2])
	{
		for(int i=0;i<size/2;i++)
		{
			if((i!=maxIndex1)&&(arr[i]>arr[maxIndex2]))
				maxIndex2=i;
		}
	}
	else if(arr[maxIndex2]>arr[maxIndex1])
	{
		for(int i=size/2;i<size;i++)
		{
			if((i!=maxIndex2)&&(arr[i]>arr[maxIndex1]))
				maxIndex1=i;
		}

	}
	return arr[maxIndex1] * arr[maxIndex2];

}
void printArray(int *arr, int size)
{
	for(int i=0;i<size;i++)
		cout<<arr[i]<<" ";
}
int main()
{
	srand(time(NULL));
	const int size =5;
	int arr[size];
	for(int i=0;i<size;i++)
		arr[i]=rand()%10;
	cout<<"The array is: ";
	printArray(arr,size);
	cout<<endl;
	int result = maxPairProduct(arr,size);
	cout<<"MaxPairProduct = "<<result<<endl;
	return 0;
}
