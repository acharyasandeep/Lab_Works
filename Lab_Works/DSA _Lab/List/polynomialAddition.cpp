#include <iostream> 
using namespace std;
class Node
{
    double coeff;
    double raisedTo;
    Node * next;
    public:
    Node(double c, double p):coeff(c),raisedTo(p),next(NULL) {}
    friend class Equation;
    ~Node()
    {
    }
};
class Equation
{
    private:
    Node* head;
    Node* tail;
    public:
    Equation():head(NULL),tail(NULL) {}
    Equation(const Equation &eq1)//copy constructor defined coz default copy constructor will do shallow copy but destructor is invoked, 
    //so we do deep copy here when we do Equation res = eq1+eq2
    //if we omit this we won't get the desired result as the res returned from operator+ is destroyed as soon as we return. 
    {
        Node* temp=eq1.head;
        while(temp!=NULL)
        {
            this->insert(temp->coeff,temp->raisedTo);
            temp=temp->next;
        }
    }
    void insert(double c, double p)
    {
        Node *newnode = new Node(c, p);
        if(head==NULL)
            head=tail=newnode;
        else
        {
            tail->next=newnode;
            tail=newnode;
        }
    }
    Equation operator+(Equation &eq1)
    {
        Equation res;
        Node* eqp=this->head;
        Node* eq1p=eq1.head;
        while(eqp!=NULL && eq1p!=NULL)
        {
            if(eqp->raisedTo > eq1p->raisedTo)
            {
                res.insert(eqp->coeff,eqp->raisedTo);
                eqp=eqp->next;
            }
            else if(eq1p->raisedTo > eqp->raisedTo)
            {
                res.insert(eq1p->coeff,eq1p->raisedTo);
                eq1p=eq1p->next;
            }
            else
            {
                res.insert(eqp->coeff+eq1p->coeff, eqp->raisedTo);
                eqp=eqp->next;
                eq1p=eq1p->next;
            }
        }
        while(eqp!=NULL)
        {
            res.insert(eqp->coeff,eqp->raisedTo);
            eqp=eqp->next;
        }
        while(eq1p!=NULL)
        {
            res.insert(eq1p->coeff,eq1p->raisedTo);
            eq1p=eq1p->next;
        }
        return res;
    } 
    void display()
    {
        Node* curr = head;
        while(curr!=NULL)
        {
            if (curr->coeff<0)
                cout<<"("<<curr->coeff<<")"<<"x^"<<curr->raisedTo;
            else
            {
                cout<<curr->coeff<<"x^"<<curr->raisedTo;
            }
            if(curr->next!=NULL)
                cout<<" + ";
            curr=curr->next;
        }
    }
    //destructor deletes all nodes to free memory 
    ~Equation()
    {
        Node* curr=head;
        while(curr!=NULL)
        {
            Node* temp=curr;
            curr=curr->next;
            delete temp;
        }
    }
};

int main()
{
    Equation eq1;
    cout<<"Equation format is: coefficient space power (eg. 2 3,2 1ff) translates to 2x^3 + 2x^1."<<endl<<endl;
    cout<<"Enter the first equation(Enter ff to finish): ";
    int c,p;
    char sep;
    while(cin>>c>>p>>sep)
    {
        eq1.insert(c,p);
    }
    cout<<"Enter the second equation(ff to finish): ";
    cin.clear();
    cin.get();
    Equation eq2;
    while(cin>>c>>p>>sep)
    {
        eq2.insert(c,p);
    }
    cout<<endl<<endl;
    cout<<"First equation: ";
    eq1.display();
    cout<<endl<<endl;
    cout<<"Second equation: ";
    eq2.display();
    Equation res=eq1+eq2;
    cout<<endl<<endl<<"Result: ";
    res.display();
    return 0;
}