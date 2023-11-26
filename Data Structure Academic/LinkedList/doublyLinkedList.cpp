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

    return 0;
}
