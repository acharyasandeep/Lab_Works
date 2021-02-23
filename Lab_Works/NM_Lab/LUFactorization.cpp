#include <iostream>
using std::cout;
using std::cin;
using std::endl;
void printMatrix(double *matrix,int n)
{
    cout<<endl<<"The solution is: "<<endl;
    for(int i=0;i<n;i++)
    {
            cout<<"X["<<i+1<<"] = "<<matrix[i];
            cout<<endl;
    }
}
int main()
{
    int n;
    cin>>n;
    double **A = new double*[n];
    double **U = new double*[n];
    double **L = new double*[n];
    for(int i=0;i<n;i++)
    {
        A[i]=new double[n];
        U[i]=new double[n];
        L[i]=new double[n];
    }
    double *B = new double[n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            if(j<n)
                cin>>A[i][j];
            else
                cin>>B[i];
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i<=j)
            {
               double sum=0;
               for(int k=0;k<i;k++)
                    sum+=L[i][k]*U[k][j];
                U[i][j]=A[i][j]-sum;
                if(i==j)
                    L[i][j]=1;
                else
                {
                    L[i][j]=0;
                }
            }
            else
            {
                double sum=0;
                for(int k=0;k<j;k++)
                    sum+=L[i][k]*U[k][j];
                L[i][j]=(A[i][j]-sum)/U[j][j];
                U[i][j]=0;
            }
            
        }
    }
    double *Y=new double[n];
    double *X=new double[n];
    for(int i=0;i<n;i++)
    {
        double sum=0;
        for(int j=0;j<i;j++)
            sum+=L[i][j]*Y[j];
        
        Y[i]=B[i]-sum;
    }
    for(int i=n-1;i>=0;i--)
    {
        double sum=0;
        for(int j=n-1;j>i;j--)
            sum+=U[i][j]*X[j];

        X[i]=(Y[i]-sum)/U[i][i];
    }
    printMatrix(X,n);

    return 0;
}