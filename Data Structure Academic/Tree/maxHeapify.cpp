#include<bits/stdc++.h>
using namespace std;

void maxHeapify(vector<int>&a,int n,int i)
{
    int large=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<n && a[left]>a[large])
    {
        large=left;
    }
    if(right<n && a[right]>a[large])
    {
        large=right;
    }

    if(large!=i)
    {
        swap(a[i],a[large]);

        maxHeapify(a,n,large);
    }
}

void printTree(vector<int>&a)
{
    for(int i:a)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int>a={12,15,8,3,9,6,4,2,7};
    int n=a.size();

    for(int i=(n/2 -1);i>=0;i--)
    {
        maxHeapify(a,n,i);
    }
    printTree(a);
}
