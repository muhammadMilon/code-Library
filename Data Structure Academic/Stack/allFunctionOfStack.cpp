#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

// Function to push an element onto the stack
struct node* push(struct node *head, int value)
{
    struct node *newNode = new node;
    newNode->data = value;
    newNode->next = head;
    return newNode;
}

// Function to pop the top element from the stack
struct node* pop(struct node *head)
{
    if (head == nullptr)
    {
        cout << "Stack is empty. Cannot pop." << endl;
    }
    else
    {
        struct node *temp = head;
        head = head->next;
        delete temp;
    }
    return head;
}

// Function to pop a specific element from the stack
struct node* popElement(struct node *head, int value)
{
    struct node *current = head;
    struct node *prev = nullptr;

    while (current != nullptr)
    {
        if (current->data == value)
        {
            if (prev != nullptr)
            {
                prev->next = current->next;
            }
            else
            {
                head = current->next;
            }
            delete current;
            return head;
        }
        prev = current;
        current = current->next;
    }

    cout << "Element " << value << " not found in the stack." << endl;
    return head;
}

// Function to print the stack
void printStack(struct node *head)
{
    if (head == nullptr)
    {
        cout << "Stack is empty." << endl;
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
    struct node *stack = nullptr;

    int choice;
    int value;

    while (true)
    {
        cout << "Stack Operations:" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop Top Element" << endl;
        cout << "3. Pop Specific Element" << endl;
        cout << "4. Print Stack" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter value to push: ";
            cin >> value;
            stack = push(stack, value);
        }
        else if (choice == 2)
        {
            stack = pop(stack);
            cout << endl<<"Popped the top element. Stack contents after pop: ";
            printStack(stack);
        }
        else if (choice == 3)
        {
            cout << "Enter value to pop: ";
            cin >> value;
            stack = popElement(stack, value);
            cout << "Stack contents after pop: ";
            printStack(stack);
        }
        else if (choice == 4)
        {
            cout << "Stack contents: ";
            printStack(stack);
        }
        else if (choice == 5)
        {
            return 0;
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
