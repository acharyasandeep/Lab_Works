#include <iostream>
using namespace std;
void merge(int arr[],int l, int m, int r)
{
	int n1 = m-l+1;
	int n2 = r-m;
	int L[n1],R[n2];
	for(int i=0;i<n1;i++)
		L[i]=arr[l+i];
	for(int j=0;j<n2;j++)
		R[j]=arr[m+j+1];
	int i=0,j=0,k=l;
	while(i<n1 && j<n2)
	{
		if(L[i]<=R[j])
		{
			arr[k]=L[i];
			i++;
		}
		else
		{
			arr[k]=R[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		arr[k]=L[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		arr[k]=R[j];
		j++;
		k++;

	}
}
void mergeSort(int arr[], int low, int high)
{
	if(low < high)
	{
		int mid = low + (high -low)/2; //for overflow prevention
		mergeSort(arr,low,mid);
		mergeSort(arr,mid+1,high);
		merge(arr,low,mid,high);

	}

}
void printArray(int arr[],int size)
{
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<< " ";
	}
	cout<<endl;

}
int main()
{
	const int size = 20;
	int arr[size];
	srand(time(NULL));
	for(int i=0;i<size;i++)
		arr[i]=rand()%100;
	cout<<"The unsorted array is: "<<endl;
	printArray(arr,size);
	mergeSort(arr,0,size-1);
	cout<<"The Sorted array is: "<<endl;
	printArray(arr,size);
	return 0;



}
