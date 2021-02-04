#include <iostream>
using namespace std;
class Node{
    int data;
    Node * next;
    public:
    Node(int value):data(value),next(NULL){}
    friend class List;
};
class List{
    Node* firstptr;
    Node* lastptr;
    public:
    List():firstptr(NULL),lastptr(NULL){}
    bool isEmpty()
    {
        return firstptr==NULL;
    }
    void insert(int value)
    {
        Node* newnode = new Node(value);
        if(isEmpty())
        {
            firstptr=lastptr=newnode;
            return;
        }
        lastptr->next = newnode;
        lastptr=newnode;
    }
    void display()
    {
        Node* curr = firstptr;
        while(curr!=NULL)
        {
            cout<<curr->data<<" ";
            curr=curr->next;
        }
        cout<<endl;
    }
    void insertAfter(int after,int value)
    {
        Node* curr=firstptr;
        Node* newnode = new Node(value);
        while(curr->data!=after)
        {
            curr=curr->next;
        }
        if(curr==lastptr)
        {
            lastptr->next = newnode;
            lastptr = newnode;
            return;
        }
        newnode->next=curr->next;
        curr->next=newnode;
        return;
    }
    void deleteNode(int value)
    {
        Node* temp=firstptr;
        Node* pretemp = temp;
        while(temp->data!=value)
        {
            pretemp=temp;
            temp=temp->next;
        }
        if(temp==firstptr)
        {
            firstptr=firstptr->next;
            temp->next=NULL;
            delete temp;
            return;
        }
        if(temp==lastptr)
        {
            lastptr=pretemp;
            lastptr->next=NULL;
            delete temp;
            return;
        }
        pretemp->next = temp->next;
        temp->next=NULL;
        delete temp;
    }
    void moveNode(int src, int dest)
    {
        // Node* srccurr=firstptr;
        // while(srccurr->data!=src && srccurr!=NULL)
        // {
        //     srccurr=srccurr->next;
        // }
        // if(srccurr==NULL)
        // {
        //     cout<<src<<" not found."<<endl;
        //     return;
        // }
        // Node* destcurr = firstptr;
        // while(destcurr->data!=dest && destcurr!=NULL)
        // {
        //     destcurr=destcurr->next;
        // }
        // if(destcurr==NULL)
        // {
        //     cout<<dest<<" not found."<<endl;
        //     return;
        // }
        deleteNode(src);
        insertAfter(dest,src);
    }
};
int main()
{
    List l1;
    l1.insert(1);
    l1.insert(2);
    l1.insert(3);
    l1.insert(4);
    l1.insert(5);
    l1.display();
    l1.moveNode(1,5);
    l1.display();
}
