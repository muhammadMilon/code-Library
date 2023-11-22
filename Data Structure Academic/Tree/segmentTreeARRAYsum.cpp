#include<bits/stdc++.h>
#define mx 100001

using namespace std;

int a[mx];
int tree[mx*3];

void init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node]=a[b];
        return;
    }
    int left=node*2;
    int right=(node*2)+1;
    int mid=(b+e)/2;

    init(left,b,mid);
    init(right,mid+1,e);

    tree[node]=tree[left]+tree[right];
}

int query(int node,int b,int e,int i,int j)
{
    if(i>e || j<b)
    {
        return 0;
    }

    if(b>=i && e<=j)
    {
        return tree[node];
    }

    int left=node*2;
    int right=(node*2)+1;
    int mid=(b+e)/2;

    int leftSum= query(left,b,mid,i,j);
    int rightSum= query(right,mid+1,e,i,j);

    return leftSum+rightSum;
}

int main()
{
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    init(1,0,n-1);
    int sum = query(1,0,n-1,0,n-1);

    cout<< sum <<endl;

    return 0;
}
