//least square method for curve fitting of polynomials
//general solution of all degree of polynomials given their degree
#include <iostream>
#include <cmath>
using namespace std;

void formMatrix(double **Mat, int deg, double *x, double *y, int n)
{
    //matrix formation with corresponding sums
    //to solve for the constants using gauss jordan method afterwards

    for(int i=0;i<deg+1;i++)
    {
        for(int j=0;j<deg+1;j++)
        {
            for(int k=0;k<n;k++)
            {
                //this loop calculate the sum and above two loops fill sum
                //in corresponding locations.
                
                Mat[i][j]+=pow(x[k],i+j);
            }
        }

        //filling sums in last column
        //by calculating sum using the following loop
        for (int k=0;k<n;k++)
            Mat[i][deg+1] += pow(x[k],i)*y[k];
    }
}

void printMatrix(double **Mat, int deg)
{
    for(int i=0;i<deg+1;i++)
    {
        for(int j=0;j<deg+2;j++)
        {
            cout<<Mat[i][j]<<"  ";
        }
        cout<<endl;
    }
}

void GaussJordanElimination(double **Mat, int deg)
{
    for(int i=0;i<deg+1;i++)
    {
        if(Mat[i][i]==0)
        {
            cout<<"Principle diagonal can't be zero.\nExiting..."<<endl;
        }

        for(int j=0;j<deg+1;j++)
        {
            if(i!=j)
            {
                double temp = Mat[j][i]/Mat[i][i];

                for(int k=0;k<deg+2;k++)
                {
                    Mat[j][k] = Mat[j][k] - Mat[i][k]*temp;
                } 
            }
        }
    }

}

int main()
{
    //matrix initialization
    int deg;//degree of polynomial
    cout<<"Enter the degree of polynomial: ";
    cin>>deg;
    cout<<"Enter the no of data: ";
    int n;
    cin>>n;

    double *x = new double[n];
    double *y = new double[n];
    cout<<"Enter the data for x: "<<endl;
    for(int i=0;i<n;i++)
        cin>>x[i];  
       

    cout<<"Enter the data for y: "<<endl;
    for(int i=0;i<n;i++)
        cin>>y[i];  
    
    double **Mat;
    //we initialize the matrix of (deg+1 * deg+2)
    Mat = new double*[deg+1];
    for(int i=0;i<deg+1;i++)
        Mat[i] = new double[deg+2];

    //Initialize the matrix to 0 at the begining.
    for(int i=0;i<deg+1;i++)
        for(int j=0;j<deg+2;j++)
            Mat[i][j] = 0;

    //Matrix formation with the corresponding sums
    
    formMatrix(Mat, deg, x, y, n);
    //cout<<"\n\nThe Augmented matrix of the normal equations is: "<<endl; 
    //printMatrix(Mat, deg);

    //After the formation of augmented matrix
    //we solve these equations using gauss-jordan elimination method...
    
    GaussJordanElimination(Mat,deg);
    
    cout<<"The solution is: y = ";
    for(int i=0;i<deg+1;i++)
        cout<<showpos<<Mat[i][deg+1]/Mat[i][i]<<"x^"<<noshowpos<<i<<" ";

    cout<<endl<<endl;
    return 0;
}
