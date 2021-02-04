#include <bits/stdc++.h>
using namespace std;
void swap(int &a ,int &b)
{
	int temp = a;
	a = b;
	b = temp;

}
void insertionSort(int A[],int size)
{
	for(int i=1;i<size;i++)
	{
		int hole = i;
		int value = A[hole];
		while(hole > 0 && A[hole-1] > value)
		{
			A[hole]=A[hole -1];
			hole = hole-1;
		}
		A[hole]=value;


	}


}
void printArray(int A[],int size)
{
	for(int i=0;i<size;i++)
		cout<<A[i]<<" ";
	cout<<endl;
}
int main()
{
	srand(time(NULL));
        const int size = 100;
        int arr[size];
        for(int i=0;i<size;i++)
		arr[i]=rand()%100;

	cout<<"Unsorted array is: "; printArray(arr, size);
	//call insertion sort
	insertionSort(arr,size);
	cout<<"After Sorting: "; printArray(arr,size);
	cout<<endl;



}
