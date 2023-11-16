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

Node *searchInBST(Node *root,int key)
{
    if(root==nullptr)
    {
        return nullptr;
    }
    if(root->data==key)
    {
        return root;
    }
    if(root->data>key)
    {
        return searchInBST(root->left,key);
    }
    return searchInBST(root->right,key);
}

int main()
{
    struct Node *root=new Node(4);
    root->left=new Node(2);
    root->right=new Node(5);
    root->left->left=new Node(1);
    root->left->right=new Node(3);
    root->right->right=new Node(6);
    if(searchInBST(root,2)==nullptr)
    {
        cout<<"This node is NOT found."<<endl;
    }
    else
    {
        cout<<"This node is found."<<endl;
    }

    return 0;
}
