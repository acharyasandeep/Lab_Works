#include <iostream>
using namespace std;
template <typename T>class Stack;
template <typename T>
class Node
{
    private:
    T data;
    Node<T>* next;
    public:
    Node<T>(T value):data(value),next(NULL) {}
    friend class Stack<T>;
};
template <typename T>
class Stack
{
    private:
    Node<T>* head;
    public:
    Stack<T>():head(NULL){}
    ~Stack<T>()
    {
        Node<T>* curr=head;
        while(curr!=NULL)
        {
            Node<T>* temp=curr;
            curr=curr->next;
            delete temp;
        }
    }
    void push(T val);
    void pop();
    bool isEmpty();
    T top();
    void display();
};
template <typename T>
bool Stack<T>::isEmpty()
{
    return head==NULL;
}
template <typename T>
void Stack<T>::push(T val)
{
    Node<T>* newnode=new Node<T>(val);
    if(isEmpty())
        head=newnode;
    else
    {
        newnode->next=head;
        head=newnode;
    }
}
template <typename T>
void Stack<T>::pop()
{
    if(isEmpty())
        cout<<"No node to delete, Empty Stack"<<endl;
    else
    {
        Node<T>* temp=head;
        head = head->next;
        delete temp;
    }
}
template <typename T>
T Stack<T>::top()
{
    if(isEmpty())
        cout<<"Stack is empty."<<endl;
    else 
        return head->data;
}
template <typename T>

void Stack<T>::display()
{
    Node<T>* curr=head;
    if(curr==NULL)
    {
        cout<<"Empty list..."<<endl;
        return;
    }
    while(curr)
    {
        cout<<curr->data<<" ";
        curr=curr->next;
    }
    cout<<endl;
}
int main()
{
    Stack<char> s;
    cout<<"Pushed a, b to stack..."<<endl;
    s.push('a');
    s.push('b');
    s.display();
    cout<<"Pushed c to stack..."<<endl;
    s.push('c');
    s.display();
    cout<<"Pop operation performed..."<<endl;
    s.pop();
    s.display();
    cout<<"Pop operation performed..."<<endl;
    s.pop();
    s.display();
    return 0;
}