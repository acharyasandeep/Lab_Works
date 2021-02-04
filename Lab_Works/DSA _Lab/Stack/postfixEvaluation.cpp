#include <iostream>
#include <string>
#include <stack>
using namespace std;
double calculate(int a, int b, char op)
{

    if (op == '+')
        return b + a;
    else if (op == '-')
        return b - a;
    else if (op == '*')
        return b * a;
    else if (op == '/')
        return b / a;
    else
        return 0;
}

int main()
{
    string postfix;
    double result;
    stack<double> st;
    cout<<"Enter postfix expression: ";getline(cin,postfix);
    for(int i=0;i<postfix.length();)
    {
        if(isdigit(postfix.at(i)))
        {
            int temp=postfix.at(i)-'0';
            i++;
            while(isdigit(postfix.at(i)))
            {
                temp=temp*10+(postfix.at(i)-'0');
                i++;
            }
            st.push(temp);
        }
            else
            {
                if(postfix.at(i)!=' ')
                {
                    double a,b;
                    char ch=postfix.at(i);
                    a=st.top();
                    st.pop();
                    b=st.top();
                    st.pop();
                    st.push(calculate(a,b,ch));
                }
                i++;
            }
    }
        cout<<"The answer is: "<<st.top()<<endl;
        st.pop();
    return 0;
}
