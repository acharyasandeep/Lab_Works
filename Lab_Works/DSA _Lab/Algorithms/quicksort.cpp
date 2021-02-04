#include <bits/stdc++.h>
using namespace std;
void swap(int &a ,int &b)
{
	int temp = a;
	a = b;
	b = temp;

}
int  partition(int arr[], int start, int end)
{
	int pivot = arr[end];
	int pIndex = start;
	for (int i = start;i<end;i++)
	{
		if(arr[i] < pivot)
		{
			swap(arr[i],arr[pIndex]);
			pIndex += 1;
		}

	}

	swap(arr[pIndex],arr[end]);
	return pIndex;

}
int partition_r(int arr[], int start, int end)
{
	srand(time(NULL));
	int randomNum = start + rand() %(end-start);
	swap(arr[randomNum],arr[end]);
	return partition(arr, start,end);

}
void quickSort(int arr[], int start, int end)
{
	if(start < end)
	{
		int pIndex = partition_r(arr, start, end);
		quickSort(arr, start, pIndex-1);
		quickSort(arr, pIndex+1, end);

	}

}
void printArray(int A[],int size)
{
	for(int i=0;i<size;i++)
		cout<<A[i]<<" ";
	cout<<endl;
}

int main(int argc , char *argv[])
{
	srand(time(NULL));
	const int size = 100;
	int arr[size];
	for(int i=0;i<size;i++)
		arr[i]=rand()%100;

	cout<<"Unsorted array is: "; printArray(arr, size);
	//call quick sort
	quickSort(arr,0,size-1);
	cout<<"After Sorting: "; printArray(arr,size);
	cout<<endl;
}

