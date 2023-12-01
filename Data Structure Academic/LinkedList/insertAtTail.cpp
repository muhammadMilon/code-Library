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

void insertAtTail(node *&head,int value)
{
    node *n=new node(value);

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

int main()
{
   node *head=nullptr;
   insertAtTail(head,1);
   insertAtTail(head,4);
   insertAtTail(head,3);
   display(head);
    return 0;
}
