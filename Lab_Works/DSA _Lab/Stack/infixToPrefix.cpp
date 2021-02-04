#include <iostream>
#include <string>
#include <stack>
using namespace std;
void SwapChar(char &a,char &b)
{
    char temp=a;
    a=b;
    b=temp;
}
bool isOperand(char c)
{
    if((c>=48 && c<=57)||(c>=65 && c<=90)||(c>=97 && c<=122)) //if number or alphabet
        return true;
    else 
        return false;
}
bool isOperator(char c)
{
    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='%')
        return true;
    else
        return false;

}
bool isBracket(char c)
{
    if(c=='('||c==')')//we consider only small brackets
        return true;
    else 
        return false;

}
int precedence(char c)
{
    if(c=='*'||c=='/'||c=='%')
        return 2;
    else //only + and - left
        return 1;

}
string infixToPostfix(string &infix)
{
    string postfix;
    stack<char> s;
    for(int i=0;i<infix.length();i++)
    {
        if(isOperand(infix.at(i)))
        {
            postfix+=infix.at(i);
        }
        else if(isOperator(infix.at(i)))
        {
            if(s.empty())
                s.push(infix.at(i));
            else
            {
                if(precedence(infix.at(i))<precedence(s.top()))
                {
                    while(!s.empty()&&s.top()!='(')
                    {
                        postfix=postfix+s.top();
                        s.pop();
                    }
                    s.push(infix.at(i));

                }
                else
                    s.push(infix.at(i));
            }
        }
        else if(isBracket(infix.at(i)))
        {
            if(infix.at(i)=='(')
                s.push(infix.at(i));
            else
            {
                while(!s.empty()&&s.top()!='(')
                {   
                    postfix=postfix+s.top();
                    s.pop();
                }
                s.pop();
            }

        }
    }
    while(!s.empty())
    {
        postfix=postfix+s.top();
        s.pop();
    }
    return postfix;
}
string reverseExpression(string expr)
{
    for(int i=0;i<expr.length();i++)
    {
        if(expr.at(i)=='(')
            expr.at(i)=')';
        else if(expr.at(i)==')')
            expr.at(i)='(';
    }
    int low=0;
    int high=expr.length()-1;
    while(low<=high)
    {
        SwapChar(expr.at(low),expr.at(high));
        high--;
        low++;
    }
    return expr;
}
int main()
{
    string infix,prefix;
    cout<<"Enter infix Expression: ";
    cin>>infix;
    infix=reverseExpression(infix);
    prefix=reverseExpression(infixToPostfix(infix));
    cout<<"The prefix expression is: "<<prefix<<endl;
    return 0;
}
