#include <iostream>
#define size 3 
using namespace std;
template<typename T>
class Dequeue
{
    private:
        int front;
        int rear;
        T data[size];
        int count;
    public:
        Dequeue():front(0),rear(-1),count(0) {}
        void pushBack(T data);
        void pushFront(T data);
        void popBack();
        void popFront();
        bool isFull();
        bool isEmpty();
        void display();
};
template<typename T>
bool Dequeue<T>::isFull()
{
    if(count==size)
        return true;
    else
        return false;
}
template <typename T>
bool Dequeue<T>::isEmpty()
{
    if(count==0)
        return true;
    else
        return false;
}
template<typename T>
void Dequeue<T>::pushBack(T val)
{
    if(isFull())
    {
        cout<<"Can't push back, DeQueue is full"<<endl;
    }
    else
    {
        rear=(rear+1)%size;
        data[rear]=val;
        count++;
    }
}
template <typename T>
void Dequeue<T>::popBack()
{
    if(isEmpty())
    {
        cout<<"Can't pop back, DeQueue is empty"<<endl;
    }
    else
    {
        T deleted=data[rear];
        if(rear==0)
            rear=size-1;
        else
            rear--;
        count--;
    }
}
template <typename T>
void Dequeue<T>::pushFront(T val)
{
    if(isFull())
    {
        cout<<"Can't push front, DeQueue is full"<<endl;
    }
    else
    {
        if(front==0)
            front=size-1;
        else
            front--;
        data[front]=val;
        count++;
    }
}
template<typename T>
void Dequeue<T>::popFront()
{
    if(isEmpty())
    {
        cout<<"Can't pop front, DeQueue is empty"<<endl;
    }
    else
    {
        T deleted=data[front];
        front=(front+1)%size;
        count--;
    }

}
template <typename T>
void Dequeue<T>::display()
{
    if(isEmpty())
    {
        cout<<"DeQueue is Empty"<<endl;
        return ;
    }
    cout<<"DeQueue: ";
    if(rear>=front)
    {
        for(int i=front;i<=rear;i++)
            cout<<data[i]<<" ";
    }
    else
    {
        for(int i=front;i<size;i++)
            cout<<data[i]<<" ";
        for(int i=0;i<=rear;i++)
            cout<<data[i]<<" ";
    }
    cout<<endl;
   
}
int main()
{
    Dequeue<int> dq1;
    char option;
    cout<<"      DeQueue menu(size:"<<size<<")"<<endl<<endl;
    cout<<"1. pushBack Operation"<<endl;
    cout<<"2. pushFront Operation"<<endl;
    cout<<"3. popBack Operation"<<endl;
    cout<<"4. popFront Operation"<<endl<<endl;

    do
    {
        int c;
        cout<<"Choose operation: "; 
        cin>>c;
        int temp;
        switch(c)
        {
            case 1:
                cout<<"Enter data to pushBack: ";
                cin>>temp;
                dq1.pushBack(temp);
                dq1.display();
                break;
            case 2:
                cout<<"Enter data to pushFront: ";
                cin>>temp;
                dq1.pushFront(temp);
                dq1.display();
                break;
            case 3:
                dq1.popBack();
                dq1.display();
                break;
            case 4:
                dq1.popFront();
                dq1.display();
                break;
        }
        cout<<endl<<"Continue (y/n): "<<endl;
        cin>>option;
    }
    while(option=='y');
 
    return 0;
}
