#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
    node(int value)
    {
        data=value;
        next=nullptr;
    }
};

void insertAtHead(node *&head,int value)
{
    node *n=new node(value);
    n->next=head;
    head=n;
}

void insertAtTail(node *&head,int value)
{
    node *n=new node (value);
    if(head==nullptr)
    {
        head=n;
        return;
    }
    node *temp=head;
    while(temp->next!=nullptr)
    {
        temp=temp->next;
    }
    temp->next=n;
}

void display(node *head)
{
    node *temp = head;
    while(temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void deletion(node *&head,int value)
{
    node *temp=head;
    while(temp->next->data!=value)
    {
        temp=temp->next;
    }

    node *toDelete=temp->next;
    temp->next=temp->next->next;

    delete toDelete;
}

bool searching(node *&head,int key)
{
    node *temp=head;
    while(temp!=nullptr)
    {
        if(temp->data==key)
        {
            return true;
        }
        temp=temp->next;
    }
    return false;
}

int main()
{
   node *head=nullptr;
   insertAtTail(head,1);
   insertAtTail(head,4);
   insertAtTail(head,3);
   display(head);
   
   cout<<"After insert at head: ";
   insertAtHead(head,4);
   display(head);
   
   cout<<"After delete: ";
   deletion(head,4);
   display(head);
   
   int key;
   cout<<"Enter a value to search: ";
   cin>>key;
   if(searching(head,key))
   {
       cout<<"The value is found."<<endl;
   }
   else
   {
       cout<<"The value is not found."<<endl;
   }
   
   deletion(head,4);
   display(head);
   
    return 0;
}
