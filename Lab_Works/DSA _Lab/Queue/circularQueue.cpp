#include <iostream>
using namespace std;
template <typename T>
class Queue
{
    private:
        static const int size=3;
        T arr[size];
        T front;
        T rear;
    public:
        Queue()
        {
            front=-1;
            rear=-1;
        }
        bool isEmpty();
        bool isFull();
        void Enqueue(T data);
        void Dequeue();
        void display();
};
template <typename T>
bool Queue<T>::isEmpty()
{
    if(front==-1)
        return true;

    return false;
}
template <typename T>
bool Queue<T>::isFull()
{
    if((rear+1)%size==front)
        return true;
    return false;
}
template <typename T>
void Queue<T>::Enqueue(T data)
{
    if(isFull())
    {
        cout<<"Operation Failed: Queue is full"<<endl;
    }
    else
    {
        if(isEmpty())
            front=rear=0;
        else
            rear=(rear+1)%size;
        arr[rear]=data;
    }
        
}
template<typename T>
void Queue<T>::Dequeue()
{
    if(isEmpty())
    {
        cout<<"Operation failed: Queue is Empty"<<endl;
    }
    else
    {
        T item=arr[front];
        if(front==rear)
            front=rear=-1;
        else
            front=(front+1)%size;
    }
}
template <typename T>
void Queue<T>::display()
{
    if(isEmpty())
    {
        cout<<"Operaton failed: Queue is Empty"<<endl;
        return ;
    }
    cout<<"Queue: ";
    if(rear>=front)
    {
        for(int i=front;i<=rear;i++)
            cout<<arr[i]<<" ";
    }
    else
    {
        for(int i=front;i<size;i++)
            cout<<arr[i]<<" ";
        for(int i=0;i<=rear;i++)
            cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    Queue<int> q1;
    char option;
    do
    {
        cout<<"      Queue menu       "<<endl<<endl;
        cout<<"1. Enqueue Operation"<<endl;
        cout<<"2. Dequeue Operation"<<endl<<endl;
        int c;
        cout<<"Choose operation: "; 
        cin>>c;
        int temp;
        switch(c)
        {
            case 1:
                cout<<"Enter data to Enqueue: ";
                cin>>temp;
                q1.Enqueue(temp);
                q1.display();
                break;
            case 2:
                q1.Dequeue();
                q1.display();
                break;
        }
        cout<<endl<<"Continue (y/n): "<<endl;
        cin>>option;
    }
    while(option=='y');

}


