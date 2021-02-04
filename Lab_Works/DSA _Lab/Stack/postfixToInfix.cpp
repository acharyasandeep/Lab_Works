#include <bits/stdc++.h>
using namespace std;
bool isOperand(char c)
{
    if((c>=48 && c<=57)||(c>=65 && c<=90)||(c>=97 && c<=122)) //if number or alphabet
        return true;
    else 
        return false;
}
int main()
{
    string postfix;
    stack<string> infix;
    cout<<"Enter postfix expression: ";cin>>postfix;
    for(int i=0;i<postfix.length();i++)
    {
        if(isOperand(postfix.at(i)))
        {
            string op(1,postfix.at(i));
            infix.push(op);
        }
        else
        {
            string op1=infix.top();
            infix.pop();
            string op2=infix.top();
            infix.pop();
            infix.push("("+op2+postfix.at(i)+op1+")");
        }

    }
    cout<<infix.top()<<endl; 
    return 0;
}
