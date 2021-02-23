#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the no of rows matrix(only square matrix, so row numbers is enough): ";cin>>n;
    vector<vector<double>> matrix(n, vector<double> (n));
    vector<vector<double>>ansMatrix(n, vector<double> (n));
    cout<<"Enter the matrix: "<<endl;
    for(int i=0;i<n;i++)
         for(int j=0;j<n;j++)
            cin>>matrix.at(i).at(j);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
                ansMatrix.at(i).at(j)=1;
            else
            {
                ansMatrix.at(i).at(j)=0;
            }              
        }
    }
    for(int i=0;i<n;i++)
    {
        if(matrix.at(i).at(i)==0)
        {
            cout<<"principle diagonal can't be zero"<<endl;
            return 0;
        }
        double pivot=matrix.at(i).at(i);
        for(int k=0;k<n;k++)
        {
            matrix.at(i).at(k)=matrix.at(i).at(k)/pivot;
            ansMatrix.at(i).at(k)=ansMatrix.at(i).at(k)/pivot;
        }
        for(int j=0;j<n;j++)
        {
            if(i!=j)
            {
                double temp=matrix.at(j).at(i);
                for(int k=0;k<n;k++)
                {
                    matrix.at(j).at(k)=matrix.at(j).at(k)-temp*matrix.at(i).at(k);
                    ansMatrix.at(j).at(k)=ansMatrix.at(j).at(k)-temp*ansMatrix.at(i).at(k);
                }

            }
        }
    }
    cout<<"The inverse matrix is: "<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<ansMatrix.at(i).at(j)<<"     ";
        }
        cout<<endl;
    }
        
    return 0;
}