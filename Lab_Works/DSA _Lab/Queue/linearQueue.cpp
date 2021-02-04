#include <iostream>
using namespace std;
template <typename T>
class Queue
{
    private:
        static const int size=5;
        T arr[size];
        T front;
        T rear;
    public:
        Queue()
        {
            front=-1;
            rear=-1;
        }
        void Enqueue(T data);
        T Dequeue();
        void display();
};
template <typename T>
void Queue<T>::Enqueue(T data)
{
    if(front==-1)
    {
        front=rear=0;
        arr[rear]=data;
    }
    else if(rear==size-1)
    {
        cout<<"Operation Failed: Queue is full"<<endl;
    }
    else
        arr[++rear]=data;    
}
template<typename T>
T Queue<T>::Dequeue()
{
    if(front==-1||front>rear)
    {
        cout<<"Operation failed: Queue is Empty"<<endl;
    }
    else
    {
        T deleted=arr[front];
        front++;
        return deleted;
    }
}
template <typename T>
void Queue<T>::display()
{
    if(front==-1)
        cout<<"Operaton failed: Queue is Empty"<<endl;
    for(int i=front;i<=rear;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
int main()
{
    Queue<int> q1;
    q1.Enqueue(1);
    q1.Enqueue(2);
    q1.Enqueue(3);
    q1.Enqueue(4);
    q1.Enqueue(5);
    //q1.Enqueue(6);
    q1.display();
    q1.Dequeue();
    q1.Dequeue();
    q1.display();
    return 0;

}

