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

Node *insertBST(Node *root,int value)
{
    if(root==nullptr)
    {
        return new Node(value);
    }
    if(value<root->data)
    {
        root->left=insertBST(root->left,value);
    }
    else
    {
        root->right=insertBST(root->right,value);
    }
    return root;
}

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
    struct Node *root=nullptr;
    root=insertBST(root,5);
    insertBST(root,1);
    insertBST(root,3);
    insertBST(root,4);
    insertBST(root,2);
    insertBST(root,7);
    insertBST(root,6);

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
