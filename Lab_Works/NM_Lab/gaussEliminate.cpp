#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cout<<"Equation is of form: a1X1 + a2X2 +...+ anXn = b"<<endl;
    cout<<"Enter the number of unknowns: ";cin>>n;
    vector<vector<double>> matrix(n, vector<double> (n+1));
    for(int i=0;i<n;i++)
        cout<<"a"<<i+1<<"      ";
    cout<<"b"<<endl;
    for(int i=0;i<n;i++)
        for(int j=0;j<n+1;j++)
            cin>>matrix.at(i).at(j);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
                if(matrix.at(i).at(i)==0)
                {
                    cout<<"principle diagonal can't be zero"<<endl;
                    return 0;
                }
                if(j > i)
                {
                    double temp=matrix.at(j).at(i)/matrix.at(i).at(i);
                    for(int k=0;k<n+1;k++)
                    {
                        matrix.at(j).at(k)=matrix.at(j).at(k)-temp*matrix.at(i).at(k);
                    }
                }
        }
    }
    vector<double> values(n);
    for(int i=n-1;i>=0;i--)
    {
        double sum=0;
        for(int k=n-1;k>i;k--)
            sum+=matrix.at(i).at(k)*values.at(k);
        values.at(i)=(matrix.at(i).at(n)-sum)/matrix.at(i).at(i);
    }
    cout<<"The solution is: "<<endl;
    for(int i=0;i<n;i++)
        cout<<"x["<<i+1<<"] = "<<values.at(i)<<endl;
        
    return 0;
}
