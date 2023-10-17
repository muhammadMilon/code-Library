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

// Function to append a new element at a certain position
void appendAtPosition(struct node *&head, int data, int position)
{
    struct node *newNode = new node;
    newNode->data = data;
    newNode->next = nullptr;

    if (position == 0)
    {
        newNode->next = head;
        head = newNode;
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

        newNode->next = current->next;
        current->next = newNode;
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

    int data, position;
    cout << "Enter the data and position to append: ";
    cin >> data >> position;
    appendAtPosition(head, data, position);

    cout << "Updated List: ";
    printList(head);

    return 0;
}
