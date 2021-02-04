#include <iostream>
using namespace std;
template <typename T> class MyList;
template <typename T>
class ListNode
{
    T data;
    ListNode* next;
    public:
    ListNode(T &val):data(val),next(NULL) {}
    friend class MyList<T>;
};
template <typename T>
class MyList 
{
    ListNode<T>* firstptr;
    ListNode<T>* lastptr;
    public:
    MyList():firstptr(NULL),lastptr(NULL) {}
    bool isEmpty();
    void insertAtFront(T val);
    void insertAtBack(T val);
    void insertAfter(T after, T val);
    void insertBefore(T before, T val);
    void deleteNodeBegining();
    void deleteNodeEnd();
    void deleteNodeAfter(T after);
    void display();
};

template <typename T>
bool MyList<T>::isEmpty()
{
    return firstptr==NULL;
}

template <typename T>
void MyList<T>::insertAtFront(T val)
{
    ListNode<T>* temp=new ListNode<T>(val);
    if(isEmpty())
    {
        firstptr=lastptr=temp;
        return;
    }
    temp->next=firstptr;
    firstptr=temp;
}
template <typename T>
void MyList<T>::insertAtBack(T val)
{
    ListNode<T>* temp=new ListNode<T>(val);
    if(isEmpty())
    {
        firstptr=lastptr=temp;
        return;
    }
    lastptr->next=temp;
    lastptr=temp;
}
template <typename T>
void MyList<T>::insertAfter(T after, T val)
{
    ListNode<T>* temp = new ListNode<T>(val);
    ListNode<T>* curr=firstptr;
    while(curr!=NULL)
    {
        if(curr->data==after)
            break;
        curr=curr->next;
    }
    if(curr==NULL)
    {
        cout<<"No such Node found"<<endl;
        return;
    }
    else
    {
        if(curr==lastptr)
        {
            curr->next=temp;
            lastptr=temp;
            return;
        }
        temp->next=curr->next;
        curr->next=temp;
    }
}
template <typename T>
void MyList<T>::insertBefore(T before, T val)
{
    ListNode<T>* temp = new ListNode<T>(val);
    ListNode<T>* curr=firstptr;
    ListNode<T>* precurr=firstptr;
    while(curr!=NULL)
    {
        if(curr->data==before)
            break;
        precurr=curr;
        curr=curr->next;
    }
    if(curr==NULL)
    {
        cout<<"No such Node found"<<endl;
        return;
    }
    else
    {
        if(curr==firstptr)
        {
            temp->next=curr;
            firstptr=temp;
            return;
        }
        temp->next=curr;
        precurr->next=temp;
    
    }

}
template <typename T>
void MyList<T>::deleteNodeBegining()
{
    if(isEmpty())
    {
        cout<<"No Node to delete."<<endl;
        return;
    }
    if(firstptr==lastptr)//only one element
    {
        ListNode<T>*temp=firstptr;
        delete temp;
        return;
    }
    ListNode<T>*temp  = firstptr;
    firstptr=firstptr->next;
    temp->next=NULL;
    delete temp;
}
template<typename T>
void MyList<T>::deleteNodeEnd()
{
    if(isEmpty())
    {
        cout<<"No node to delete."<<endl;
        return;
    }
    if(firstptr==lastptr)
    {
        firstptr=lastptr=NULL;
        return;
    }
    ListNode<T>*secondLast = firstptr;
    while(secondLast->next!=lastptr)
    {
        secondLast=secondLast->next;
    }
    ListNode<T>*temp=lastptr;
    secondLast->next=NULL;
    lastptr=secondLast;
    delete temp;
    return;
}
template<typename T>
void MyList<T>::deleteNodeAfter(T after)
{
    if(isEmpty())
    {
        cout<<"No Nodes to delete."<<endl;
        return;
    }
    if(firstptr==lastptr)
    {
        cout<<"Only one node in the list. Can't perform this operation."<<endl;
        return;
    }
    ListNode<T>*curr=firstptr;
    while(curr->data!=after && curr!=NULL)
        curr=curr->next;
    if(curr==NULL)
    {
        cout<<"No such node having value "<<after<<" exists in the list."<<endl;
        return;
    }
    if(curr->next==lastptr)
    {
        deleteNodeEnd();
        return;
    }
    ListNode<T>*temp=curr->next;
    curr->next=temp->next;
    temp->next=NULL;
    delete temp;

}

    
template<typename T>
void MyList<T>::display()
{
    cout<<"List: ";
    if(isEmpty())
    {
        return;
    }
    ListNode<T>* temp = firstptr;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void printMenu()
{
    cout<<"          List Menu"<<endl<<endl;
    cout<<"1. Insert at the begining."<<endl;
    cout<<"2. Insert at the end."<<endl;
    cout<<"3. Insert after specific node."<<endl;
    cout<<"4. Insert before specific node."<<endl;
    cout<<"5. Delete node from begining."<<endl;
    cout<<"6. Delete node from end."<<endl;
    cout<<"7. Delete after specific node."<<endl<<endl;
}



int main()
{
    MyList<int> l1;
    char ch;
    printMenu();
    do
    {
        int option;
        int value,select;//value- value to insert, select - to find the node after before
        cout<<"Choose option: ";cin>>option;
        if(cin.fail())
            break;
        switch(option)
        {
            case 1:
                cout<<"Enter the value to be inserted in the begining: ";
                cin>>value;
                l1.insertAtFront(value);
                l1.display();
                break;
            case 2:
                cout<<"Enter the value to be inserted in the end: ";
                cin>>value;
                l1.insertAtBack(value);
                l1.display();
                break;
            case 3:
                cout<<"After which node: ";
                cin>>select;
                cout<<"Value to be inserted: ";
                cin>>value;
                l1.insertAfter(select, value);
                l1.display();
                break;
            case 4:
                cout<<"Before which node: ";
                cin>>select;
                cout<<"Value to be inserted: ";
                cin>>value;
                l1.insertBefore(select, value);
                l1.display();
                break;
            case 5:
                l1.deleteNodeBegining();
                l1.display();
                break;
            case 6:
                l1.deleteNodeEnd();
                l1.display();
                break;
            case 7:
                cout<<"Delete after which node: ";
                cin>>select;
                l1.deleteNodeAfter(select);
                l1.display();
                break;
            default:
                cout<<"Please enter the correct option";
                break;
        }
        cout<<endl<<"Continue (y/n): ";cin>>ch;
    }while(ch=='y'||ch=='Y');
    return 0;
}
