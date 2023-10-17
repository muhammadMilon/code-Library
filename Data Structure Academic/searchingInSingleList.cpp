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
            cout  << temp->data<<" ";
            temp = temp->next;
        }
    }
    cout<<endl;
}

// Function to search for an element in the linked list
int searchList(struct node *head, int target)
{
    struct node *temp = head;
    int position = 1;
    while (temp != nullptr)
    {
        if (temp->data == target)
        {
            return position; // Element found
        }
        temp = temp->next;
        position++;
    }
    return -1; // Element not found
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

    int target;
    cout << "Enter the element to search for: ";
    cin >> target;

    int position = searchList(head, target);
    if (position != -1)
    {
        cout << "Element " << target << " found at position " << position << " in the list." << endl;
    }
    else
    {
        cout << "Element " << target << " not found in the list." << endl;
    }

    return 0;
}
