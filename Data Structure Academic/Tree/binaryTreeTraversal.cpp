#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int value)
    {
        data=value;
        left=nullptr;
        right=nullptr;
    }
};

void preOrder(struct Node *root)
{
    if(root)
    {
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(struct Node *root)
{
    if(root)
    {
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}

void postOrder(struct Node *root)
{
    if(root)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
    }
}

int main()
{
    struct Node *root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);

    cout<<"Pre Order Traversal: ";
    preOrder(root);
    cout<<endl;

    cout<<"In Order Traversal: ";
    inOrder(root);
    cout<<endl;

    cout<<"Post Order Traversal: ";
    postOrder(root);
    cout<<endl;

    return 0;
}
