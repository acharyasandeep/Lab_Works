#include <iostream>
using namespace std;
template <typename T> class Queue;
template <typename T>
class Node
{
    private:
    T data;
    Node<T> * next;
    public:
    Node<T>(T val):data(val),next(NULL) {}
    friend class Queue<T>;
};
template <typename T>
class Queue
{
    private:
    Node<T>* firstptr;
    Node<T>* lastptr;
    public:
    Queue<T>():firstptr(NULL),lastptr(NULL) {}
    ~Queue<T>()
    {
        Node<T>*curr=firstptr;
        while(curr!=NULL)
        {
            Node<T>*temp=curr;
            curr=curr->next;
            delete temp;
        }
    }
    bool isEmpty();
    void Enqueue(T val);
    void Dequeue();
    T front();
    T back();
    void display();
};
template <typename T>
bool Queue<T>::isEmpty()
{
    return firstptr==NULL;
}
template <typename T>
void Queue<T>::Enqueue(T val)
{
    Node<T>* newnode = new Node<T>(val);
    if(isEmpty())
    firstptr=lastptr=newnode;
    else
    {
        lastptr->next=newnode;
        lastptr=newnode;
    }
}
template <typename T>
void Queue<T>::Dequeue()
{
    if(isEmpty())
    cout<<"No element to dequeue, Empty queue"<<endl;
    else
    {
        Node<T>* temp = firstptr;
        firstptr=firstptr->next;
        delete temp;
    }
}
template <typename T>
T Queue<T>::front()
{
    if(isEmpty())
    cout<<"Queue's Empty."<<endl;
    else
    {
        return firstptr->data;
    }
}
template <typename T>
T Queue<T>::back()
{
    if(isEmpty())
    cout<<"Queue's Empty"<<endl;
    else
    {
        return lastptr->data;
    }
    
}
template <typename T>
void Queue<T>::display()
{
    if(isEmpty())
    cout<<"Queue's Empty."<<endl;
    else
    {
        Node<T>* curr=firstptr;
        while(curr)
        {
            cout<<curr->data<<" ";
            curr=curr->next;
        }
        cout<<endl;
    }   
}
int main()
{
    Queue<char> q;
    cout<<"Enqueue operation for a,b,c,d"<<endl;
    q.Enqueue('a');
    q.Enqueue('b');
    q.Enqueue('c');
    q.Enqueue('d');
    q.display();
    cout<<"Dequeue operation performed "<<endl;
    q.Dequeue();
    cout<<"Dequeue operation performed "<<endl;
    q.Dequeue();
    cout<<"Dequeue operation performed"<<endl;
    q.Dequeue();
    q.display();
    cout<<"Dequeue operation performed"<<endl;
    q.Dequeue();
    q.display();
    q.Dequeue();
    return 0;
}