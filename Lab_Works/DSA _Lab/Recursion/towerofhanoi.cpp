#include <iostream>
using namespace std;
void toh(int n, char src, char aux, char dest)
{
    if(n==1)
    {
        cout<<"Move top disk from "<<src<<" to "<<dest<<"."<<endl;
        return;
    }
    toh(n-1,src,dest,aux);
    cout<<"Move top disk from "<<src<<" to "<<dest<<"."<<endl;
    toh(n-1,aux,src,dest);
}
int main()
{
    int n;
    cout<<"Enter the no of disks: ";cin>>n;
    toh(n,'A','B','C');
    return 0;
}