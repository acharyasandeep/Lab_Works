#include <iostream>
#include <string>
using namespace std;
class StackError
{
    string errorDesc;
    public:
    StackError(string s)
    {
        errorDesc=s;
    }
    void display()
    {
        cout<<"Error: "<<errorDesc<<endl;
    }
};
template <typename T>
class Stack{
    private:
        int top=-1;
        static const int size=5;
        T Arr[size];
    public:
        bool isEmpty();
        bool isFull();
        void push(T);
        T pop();
        T peak();
        void display();
        
};
template<typename T>
bool Stack<T>::isEmpty()
{
    if(top<0)
        return true;
    else
        return false;
}
template<typename T>
bool Stack<T>::isFull()
{
    if(top>=size-1)
        return true;
    else
        return false;
}
template<typename T>
void Stack<T>::push(T data)
{
    try
    {
        if(isFull())
        {
            throw StackError(string("Full Stack Exception"));
        }
        else
            Arr[++top]=data;
    }
    catch(StackError e)
    {
        e.display();
    }
}
template<typename T>
T Stack<T>::pop()
{
    try
    {
        if(isEmpty())
        {
            throw StackError(string("Empty Stack exception"));
        }
        else
        {
            T temp=Arr[top];
            top--;
            return temp;
        }
    
    }
    catch(StackError e)
    {
        e.display();
    }
    
    
}
template<typename T>
T Stack<T>::peak()
{
    try
    {
        if(isEmpty())
        {
            throw StackError(string("Empty Stack Exception"));
        }
        else
            return Arr[top];
    }
    catch(StackError e)
    {
        e.display();
    }
}
int main()
{
    Stack<int> S;
    S.push(1);
    S.push(2);
    S.push(3);
    S.push(4);
    S.push(5);
    S.pop();
    S.pop();
    S.pop();
    S.pop();
    S.pop();
    cout<<S.peak()<<endl;
    return 0;
}
