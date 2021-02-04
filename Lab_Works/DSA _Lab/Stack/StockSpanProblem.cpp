//StockSpan problem taken from geek for geeks
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    stack<int> s;
    stack<int> s1;
    vector<int> cnt(n,0);
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        s.push(temp);
        while(!s.empty()&&s.top()<=temp)
        {
            cnt.at(i)++;
            s1.push(s.top());
            s.pop();
        }
        while(!s1.empty())
        {
            s.push(s1.top());
            s1.pop();
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<cnt.at(i)<<" ";
        
    }
    cout<<endl;
}
