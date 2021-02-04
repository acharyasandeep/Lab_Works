#include <iostream>
using namespace std;
template<typename T> class List;
template <typename T>
class Node 
{
    T data;
    Node<T>* next;
    Node<T>* prev;
    public:
    Node<T>(T value):prev(NULL),next(NULL),data(value) {}
    friend class List<T>;
};
template<typename T>
class List
{
    Node<T>* first;
    Node<T>* last;
    public:
    List<T>():first(NULL),last(NULL) {}
    bool isEmpty();
    void insertAtBegining(T value);
    void insertAtEnd(T value);
    void insertAfter(T after, T value);
    void insertBefore(T before, T value);
    void deleteFromBegining();
    void deleteFromEnd();
    void deleteAfter(T after);
    void deleteBefore(T before);
    void display();
    ~List<T>()
    {
        Node<T>*curr = first;
        while(curr!=NULL)
        {
            Node<T>*temp = curr;
            curr=curr->next;
            temp->next=NULL;
            delete temp;
        }
    }
};
template <typename T>
bool List<T>::isEmpty()
{
    return first==NULL;
}
template <typename T>
void List<T>::insertAtBegining(T value)
{
    Node<T> *newnode = new Node<T>(value);
    if(isEmpty())
    {
        first=last=newnode;
        return;
    }
    newnode->next=first;
    first->prev=newnode;
    first=newnode;
}
template <typename T>
void List<T>::insertAtEnd(T value)
{
    Node<T> *newnode = new Node<T>(value);
    if(isEmpty())
    {
        first=last=newnode;
        return;
    }
    last->next=newnode;
    newnode->prev=last;
    last=newnode;
}
template <typename T>
void List<T>::insertAfter(T after, T value)
{
    if(isEmpty())
    {
        cout<<"List is empty"<<endl;
        return;
    }
    Node<T>* curr=first;
    while(curr!=NULL && curr->data!=after)
    {
        curr=curr->next;
    }
    if(curr==NULL)
    {
        cout<<"Failed. "<<after<<" wasn't found on the list."<<endl;
        return;
    }
    if(curr==last)
    {
        insertAtEnd(value);
        return;
    }
    Node<T>* newnode = new Node<T>(value);
    newnode->prev = curr;
    newnode->next = curr->next;
    curr->next->prev = newnode;
    curr->next=newnode;
}
template <typename T>
void List<T>::insertBefore(T before, T value)
{
    Node<T>* curr=first;

    while(curr!=NULL && curr->data!=before)
    {
        curr=curr->next;
    }
    if(curr==NULL)
    {
        cout<<"Failed. "<<before<<" wasn't found on the list."<<endl;
        return;
    }
    if(curr==first)
    {
        insertAtBegining(value);
        return;
    }
    Node<T>* newnode = new Node<T>(value);
    newnode->prev = curr->prev;
    newnode->next = curr;
    curr->prev->next = newnode;
    curr->prev=newnode;
}
template <typename T>
void List<T>::deleteFromBegining()
{
    if(isEmpty())
    {
        cout<<"No node to delete."<<endl;
        return;
    }
    if(first==last)
    {
        delete first;
        first=last=NULL;  
        return;
    }
    Node<T>* temp = first;
    first=first->next;
    first->prev=NULL;
    temp->next=NULL;
    delete temp;

}
template <typename T>
void List<T>::deleteFromEnd()
{
    if(isEmpty())
    {
        cout<<"No node to delete."<<endl;
        return;
    }
    if(first==last)
    {
        Node<T>* temp = first;
        temp->next=NULL;
        delete temp;
        temp=NULL;
        return;
    }
    Node<T>* temp=last;
    last=last->prev;
    last->next=NULL;
    temp->prev=NULL;
    delete temp;
}
template <typename T>
void List<T>::deleteAfter(T after)
{
    Node<T>* curr=first;
    while(curr!=NULL && curr->data!=after)
    {
        curr=curr->next;
    }
    if(curr==NULL)
    {
        cout<<"Failed. "<<after<<" wasn't found on the list."<<endl;
        return;
    }
    else if(curr==last)
    {
        cout<<"Failed. No node is present after "<<after<<"."<<endl;
        return;
    }
    else if(curr->next==last)
    {
        deleteFromEnd();
        return;
    }
    Node<T>* temp = curr->next;
    curr->next = temp->next;
    temp->next->prev = curr;
    temp->next=NULL;
    temp->prev=NULL;
    delete temp;
}
template <typename T>
void List<T>::deleteBefore(T before)
{
    Node<T>* curr=first;
    while(curr!=NULL && curr->data!=before)
    {
        curr=curr->next;
    }
    if(curr==NULL)
    {
        cout<<"Failed. "<<before<<" wasn't found on the list."<<endl;
        return;
    }
    else if(curr==first)
    {
        cout<<"Failed. No node is present before "<<before<<"."<<endl;
        return;
    }
    else if (curr->prev==first)
    {
        deleteFromBegining();
        return;
    }
    Node<T>* temp = curr->prev;
    curr->prev = temp->prev;
    temp->prev->next = curr;
    temp->prev=NULL;
    temp->next=NULL;
    delete temp;
}
template <typename T>
void List<T>::display()
{
    Node<T>* curr= first;
    cout<<"List: ";
    while(curr!=NULL)
    {
        cout<<curr->data<<" ";
        curr=curr->next; 
    }
}
void printMenu()
{
    cout<<"         Menu"<<endl<<endl;
    cout<<"1. Insert at the begining"<<endl;
    cout<<"2. Insert at the end"<<endl;
    cout<<"3. Insert after specific node"<<endl;
    cout<<"4. Insert before specific node"<<endl;
    cout<<"5. Delete from begining"<<endl;
    cout<<"6. Delete from end"<<endl;
    cout<<"7. Delete after specific node"<<endl;
    cout<<"8. Delete before specific node"<<endl;
}
int main()
{
    List<double> l1;
    printMenu();
    int choice;
    char again;
    double value;
    double findData;
    do
    {
        cout<<"Enter your choice: ";cin>>choice;
        cout<<endl;
        switch(choice)
        {
            case 1:
            cout<<"Enter the value to insert: ";cin>>value;
            l1.insertAtBegining(value);
            l1.display();
            break;
            
            case 2:
            cout<<"Enter the value to insert: ";cin>>value;
            l1.insertAtEnd(value);
            l1.display();
            break;
            
            case 3:
            cout<<"Insert after the value: ";cin>>findData;
            cout<<"Value to be inserted: ";cin>>value;
            l1.insertAfter(findData,value);
            l1.display();
            break;
            
            case 4:
            cout<<"Insert before the value: ";cin>>findData;
            cout<<"Value to be inserted: ";cin>>value;
            l1.insertBefore(findData,value);
            l1.display();
            break;

            case 5:
            l1.deleteFromBegining();
            l1.display();
            break;

            case 6:
            l1.deleteFromEnd();
            l1.display();
            break;

            case 7:
            cout<<"Delete after the value: ";cin>>findData;
            l1.deleteAfter(findData);
            l1.display();
            break;
            
            case 8:
            cout<<"Delete before the value: ";cin>>findData;
            l1.deleteBefore(findData);
            l1.display();
            break;

            default:
            cout<<"wrong choice"<<endl;
            l1.display();
            break;
        }
        cout<<endl<<"Continue: ";
        cin>>again;
        if(cin.eof())
            break;
    } while (again=='y');  
    return 0;
}