#include <iostream>
using namespace std;
void swap(int &a , int &b)
{
    int temp = a;
    a=b;
    b=temp;
}
void printArray(int * arr,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void insertionSort(int *arr,int gap,int size)
{
    for(int i=gap;i<size;i++)
    {
        int hole = i;
        int value = arr[hole];
        while(hole >= gap && arr[hole-gap]>value)
        {
            arr[hole] = arr[hole-gap];
            hole-=gap;
        }
        arr[hole] = value;
    }
}

void shellSort(int *arr , int n)
{
    int gap = n/2;
    while(gap>0)
    {
        cout<<"Gap = "<<gap<<endl;
        insertionSort(arr,gap,n);

//        gap=(gap+1)/2;
//
//        for(int i=0;i<n-gap;i++)
//        {
//            if(arr[gap+i]<arr[i])
//            {
//                swap(arr[gap+i],arr[i]);
//            }
//        }
        printArray(arr,n);
        gap=gap/2;
    }
}
int main()
{
//    int *arr;
//    int n;
//    cout<<"Enter the no of elements: ";cin>>n;
//    arr = new int[n];
//
//    for(int i=0;i<n;i++)
//    {
//        cin>>arr[i];
//    }

    const int n=10;
    int arr[n]={92,83,22,49,36,98,12,9,70,51};
    shellSort(arr, n);
    printArray(arr, n);
}
