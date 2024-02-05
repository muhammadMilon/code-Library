#include<bits/stdc++.h>
using namespace std;

#define mx 10000
int parent[mx];

void makeSet(int u)
{
    parent[u]=u;
}

void init()
{
    for(int i=1;i<=8;i++)
    {
        makeSet(i);
    }
}

int Find(int u)
{
    if(u==parent[u])
    {
        return u;
    }
    return Find(parent[u]);
}

void Union(int u,int v)
{
    int p=Find(u);
    int q=Find(v);

    if(p!=q)
    {
        parent[q]=p;
    }
}

bool isFriend(int u,int v)
{
    return Find(u)==Find(v);
}

int main()
{
    init();

    Union(4,2);
    Union(1,5);
    Union(5,2);
    Union(3,4);
    Union(7,1);

    if(isFriend(3,7))
    {
        cout<<"Yes,They are friend."<<endl;
    }
    else
    {
        cout<<"No,They are not friend."<<endl;
    }
    
    return 0;
}
