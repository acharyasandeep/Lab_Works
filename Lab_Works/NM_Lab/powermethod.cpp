//power method to find eigen value and eigen vectors
//
#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the order of square matrix: ";cin>>n;
    vector<vector<double>> A(n,  vector<double>(n,0)); //square matrix of order n
    
    //Read square matrix A
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<"A["<<i+1<<"]"<<"["<<j+1<<"]: ";
            cin>>A[i][j];
        }
    }

    vector<double> guessEigenVector(n,1),eigenVector(n,0),errorVector(n,0);
    double eigenValue=0,errorTol, MAXITR=100,errorMax=0;
    cout<<"Enter error tolerance: ";cin>>errorTol;

    cout<<"\nEnter initial guess vector"<<endl;
    for(int i=0;i<n;i++)
        cin>>guessEigenVector[i];

    int count=0;
    do
    {
        count++;
        if(count>MAXITR)
        {
            cout<<"Maximum iterations exceeded.\nExiting...\n";
            return -1;
        }

        //display each iteration
        //cout<<"X"<<count<<": "<<endl;
        //for(int i=0;i<n;i++)
            //cout<<guessEigenVector[i]<<endl;


        //compute eigenVector = A*guessEigenVector;
        for(int i=0;i<n;i++)
        {
            double val=0;
            for(int j=0;j<n;j++)
                val = val + A[i][j]*guessEigenVector[j];

            eigenVector[i] = val;
        }

        //compute largest absolute value from eigenVector

        eigenValue = abs(eigenVector[0]);
        for(int i=1;i<n;i++)
        {
            if(abs(eigenVector[i])>eigenValue)
                eigenValue = abs(eigenVector[i]);
        }
        //scale eigen vector by eigen value eigenVector = eigenVector/eigenValue
        for(int i=0;i<n;i++)
            eigenVector[i]=eigenVector[i]/eigenValue;

        //compute error between eigenVector and guessEigenVector
        
        for(int i=0;i<n;i++)
                errorVector[i] = abs(abs(eigenVector[i])-abs(guessEigenVector[i]));
        //replace guessEigenVector by eigenVector
        for(int i=0;i<n;i++)
            guessEigenVector[i] = eigenVector[i];

        //compute the largest error

        errorMax = errorVector[0];
        for(int i=0;i<n;i++)
        {
            if(errorVector[i]>errorMax)
                errorMax = errorVector[i];
        }
    }
    while(errorMax > errorTol);

   //display result 
    cout<<"\nThe largest eigen value is: "<<eigenValue<<endl;
    cout<<"The eigen vector is:\n\n";
    cout<<"[";
    for(int i=0;i<n;i++)
    {
        cout<<guessEigenVector[i]<<" ";
    }
    cout<<"]"<<endl;


    //converting eigenVector to normal form
    double norm=0;
    for(int i=0;i<n;i++)
        norm+=pow(guessEigenVector.at(i),2);
    
    for(int i=0;i<n;i++)
        guessEigenVector.at(i) = guessEigenVector.at(i)/sqrt(norm);
    
    //eigen vector in normal form
    //
    cout<<"The eigen vector in normal form is:\n\n";
    cout<<"[";
    for(int i=0;i<n;i++)
    {
        cout<<guessEigenVector[i]<<" ";
    }
    cout<<"]"<<endl;
    return 0;
}
