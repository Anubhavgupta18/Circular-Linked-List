#include<iostream>
#include<conio.h>
using namespace std;
class circular_linked_list
{
private:
    struct node
    {
        int item;
        node *next;
    };
    node *last;
public:
    circular_linked_list();
    ~circular_linked_list();
    void insert_first(int data);
    void insert_last(int data);
    void delete_first();
    void delete_last();
    void insert_AfterElement(int element,int data);
    void delete_element(int element);
    void viewListItems();
};
circular_linked_list::circular_linked_list()
{
    last=NULL;
}
circular_linked_list::~circular_linked_list()
{
    while(last)
    {
        delete_first();
    }
}
void circular_linked_list::insert_first(int data)
{
    node *n=new node;
    n->item=data;
    if(last==NULL)
    {
        last=n;
        last->next=last;
    }
    else
    {
        n->next=last->next;
        last->next=n;
    }
}
void circular_linked_list::viewListItems()
{
    node *temp=last->next;
    while(temp!=last)
    {
        cout<<temp->item<<" ";
        temp=temp->next;
    }
    cout<<temp->item<<" ";
}
void circular_linked_list::insert_last(int data)
{
    node *n=new node;
    n->item =data;
    if(last==NULL)
    {
        last=n;
        last->next=last;
    }
    else
    {
        n->next=last->next;
        last->next=n;
        last=n;
    }
}
void circular_linked_list::delete_first()
{
    if(last==NULL)
    {
        cout<<"OPERATION FAILED:CIRCULAR LINKED LIST IS EMPTY!"<<endl;
    }
    else
    {
        if(last->next==last)
        {
            delete last;
            last=NULL;
        }
        else
        {
            node *temp=last->next;
            last->next=last->next->next;
            delete temp;
        }
    }
}
void circular_linked_list::delete_last()
{
    if(last==NULL)
    {
        cout<<"OPERATION FAILED:CIRCULAR LINKED LIST IS EMPTY!"<<endl;
    }
    else
    {
        if(last->next==last)
        {
            delete last;
            last=NULL;
        }
        else
        {
            node *t=last->next;
            while(t->next!=last)
            {
               t=t->next;
            }
            t->next=last->next;
            delete last;
            last=t;

        }
    }
}
void circular_linked_list::insert_AfterElement(int element,int data)
{
    if(last==NULL)
    {
        cout<<"OPERATION FAILED:CIRCULAR LINKED LIST IS EMPTY!"<<endl;
    }
    else
    {
        node *temp=last->next;
        while(temp!=last)
        {
            if(temp->item==element)
            {
                break;
            }
            temp=temp->next;
        }
        if(temp==last)
        {
            if(temp->item==element)
            {
               insert_first(data);
            }
            else
            {
                cout<<"OPERATION FAILED:ELEMENT NOT FOUND!"<<endl;
            }
        }
        else
        {
            node *n=new node;
            n->item=data;
            n->next=temp->next;
            temp->next=n;
        }
    }
}
void circular_linked_list::delete_element(int element)
{
    if(last==NULL)
    {
        cout<<"OPERATION FAILED:CIRCULAR LINKED LIST IS EMPTY!"<<endl;
    }
    else
    {
        node *t1=last->next,*t2=NULL;
        while(t1!=last)
        {
            if(t1->item==element)
            {
                break;
            }
            t2=t1;
            t1=t1->next;
        }
        if(t1==last)
        {
            if(t1->item==element)
            {
                delete_last();
            }
            else
            {
                cout<<"OPERATION FAILED:ELEMENT NOT FOUND!"<<endl;
            }
        }
        else
        {
            if(t2==NULL)
            {
                delete_first();
            }
            else
            {
                t2->next=t1->next;
                delete t1;
            }
        }
    }
}
