#include <iostream>
using namespace std;
void printArray(double **array,int row,int column)
{
    cout<<endl<<"The matrix is: "<<endl;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            cout<<array[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int row,column;
    cout<<"Enter row and column of matrix: ";cin>>row>>column;
    double** arr;
    arr = new double*[row];
    for(int i=0;i<row;i++)
        arr[i]=new double[column];
    cout<<"Enter matrix:"<<endl;
    for(int i=0;i<row;i++)
        for(int j=0;j<column;j++)
            cin>>arr[i][j];
    printArray(arr,row,column);
    return 0;   
}