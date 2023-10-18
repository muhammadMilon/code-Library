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

// Function to merge two lists
struct node* mergeLists(struct node *list1, struct node *list2)
{
    struct node dummy;
    struct node *tail = &dummy;
    dummy.next = nullptr;

    while (list1 != nullptr && list2 != nullptr)
    {
        if (list1->data <= list2->data)
        {
            tail->next = list1;
            list1 = list1->next;
        }
        else
        {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    if (list1 != nullptr)
        tail->next = list1;
    else
        tail->next = list2;

    return dummy.next;
}

int main()
{
    struct node *head1 = nullptr;
    struct node *current1 = nullptr;
    struct node *head2 = nullptr;
    struct node *current2 = nullptr;

    int numElements1, numElements2;
    cout << "Enter the number of elements for List 1: ";
    cin >> numElements1;
    cout << "Enter the Elements for List 1: ";

    for (int i = 0; i < numElements1; i++)
    {
        struct node *newNode = new node;
        cin >> newNode->data;
        newNode->next = nullptr;

        if (head1 == nullptr)
        {
            head1 = newNode;
            current1 = newNode;
        }
        else
        {
            current1->next = newNode;
            current1 = newNode;
        }
    }

    cout << "Enter the number of elements for List 2: ";
    cin >> numElements2;
    cout << "Enter the Elements for List 2: ";

    for (int i = 0; i < numElements2; i++)
    {
        struct node *newNode = new node;
        cin >> newNode->data;
        newNode->next = nullptr;

        if (head2 == nullptr)
        {
            head2 = newNode;
            current2 = newNode;
        }
        else
        {
            current2->next = newNode;
            current2 = newNode;
        }
    }

    cout << "List 1: ";
    printList(head1);
    cout << "List 2: ";
    printList(head2);

    // Merge the two lists
    struct node *mergedList = mergeLists(head1, head2);

    cout << "Merged List: ";
    printList(mergedList);

    return 0;
}
