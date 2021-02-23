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
            if(i!= j)
            {
                if(matrix.at(i).at(i)==0)
                {
                    cout<<"principle diagonal can't be zero"<<endl;
                    return 0;
                }
                double temp=matrix.at(j).at(i)/matrix.at(i).at(i);
                for(int k=0;k<n+1;k++)
                {
                    matrix.at(j).at(k)=matrix.at(j).at(k)-temp*matrix.at(i).at(k);
                }
            }
        }
    }
    cout<<"The solution is: "<<endl;
    for(int i=0;i<n;i++)
        cout<<"X"<<i+1<<" = "<<matrix.at(i).at(n)/matrix.at(i).at(i)<<endl;
        
    return 0;
}
