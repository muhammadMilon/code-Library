#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;

    Node(int value)
    {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

void insertAtHead(struct Node *&head, int value)
{
    Node *n = new Node(value);
    n->next = head;
    if (head != nullptr)
    {
        head->prev = n;
    }
    head = n;
}

void insertAtTail(struct Node *&head, int value)
{
    if (head == nullptr)
    {
        insertAtHead(head, value);
        return;
    }
    Node *n = new Node(value);
    Node *temp = head;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}

void display(struct Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteAtHead(struct Node *&head)
{
    Node *todelete=head;
    head=head->next;
    head->prev=nullptr;

    delete todelete;
}

void deletion(struct Node *&head,int pos)
{
    if(pos==1)
    {
        deleteAtHead(head);
        return;
    }
    Node *temp=head;
    int cnt=1;
    while(temp!=nullptr && cnt!=pos)
    {
        temp=temp->next;
        cnt++;
    }
    temp->prev->next=temp->next;
    if(temp->next!=temp)
    {
        temp->next->prev=temp->prev;
    }

    delete temp;
}

int main()
{
    Node *head = nullptr;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    display(head);
    insertAtHead(head, 6);
    display(head);
    deletion(head,1);
    display(head);

    return 0;
}
