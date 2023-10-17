#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

void printList(struct node *head)
{
    if (head == nullptr)
    {
        cout << "Empty" << endl;
    }
    else
    {
        struct node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main()
{
    struct node *head = nullptr;
    struct node *current = nullptr;

    int numElements;
    cout << "Enter the number of elements: ";
    cin >> numElements;
    cout<<"Enter the Elements: ";

    for (int i = 0; i < numElements; i++)
    {
        struct node *newNode = new node;
        cin >> newNode->data;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
            current = newNode;
        }
        else
        {
            current->next = newNode;
            current = newNode;
        }
    }
    cout<<"The List is: ";
    printList(head);

    return 0;
}
