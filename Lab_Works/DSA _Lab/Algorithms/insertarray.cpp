#include <iostream>
#include <chrono>
using namespace std::chrono;
 auto start = high_resolution_clock::now();
using namespace std;
void insertarray(int arr[], int ,int,int);
int main()
{

    int newarr[4] = {0,1,2,3};
    cout<<"The given array is: ";
    for (int i=0;i<4;i++)
        cout<<newarr[i]<<" ";
    cout<<endl;

    insertarray(newarr,4,10,2 );

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop-start);
    cout<<endl<<"Execution time: "<<duration.count()<<" microseconds"<<endl;
}

void insertarray(int arr[],int length,int num, int pos)
{
int newarr[length + 1];
pos=pos-1;
for(int i =0; i<length+1;i++)
{

    if(i < pos)
        newarr[i]  = arr[i];
    else if(i == pos)
        newarr[i]= num;
    else
        newarr[i] = arr[i-1];
}

    cout<<"After inserting "<<num<<" at postition "<<pos+1<<endl;
    for(int i=0;i<length+1;i++)
        cout<<newarr[i]<<" ";
}
