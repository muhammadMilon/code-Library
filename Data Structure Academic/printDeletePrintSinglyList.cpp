#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

// Function to print the List
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

// Function to delete an element at a certain position
void deleteAtPosition(struct node *head, int position)
{
    if (head == nullptr)
    {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }

    if (position == 0)
    {
        struct node *temp = head;
        head = head->next;
        delete temp;
    }
    else
    {
        struct node *current = head;
        int currentPosition = 0;

        while (currentPosition < position - 1 && current->next != nullptr)
        {
            current = current->next;
            currentPosition++;
        }

        if (current->next == nullptr)
        {
            cout << "Position not found. Cannot delete." << endl;
        }
        else
        {
            struct node *temp = current->next;
            current->next = temp->next;
            delete temp;
        }
    }
}

int main()
{
    struct node *head = nullptr;
    struct node *current = nullptr;

    int numElements;
    cout << "Enter the number of elements: ";
    cin >> numElements;
    cout << "Enter the Elements: ";

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

    cout << "The List is: ";
    printList(head);

    int position;
    cout << "Enter the position to delete: ";
    cin >> position;

    deleteAtPosition(head, position - 1);

    cout << "Updated List after delete: ";
    printList(head);

    return 0;
}
