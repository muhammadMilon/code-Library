#include<bits/stdc++.h>
using namespace std;

#define mx 100000
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
    int p=Find(u);
    int q=Find(v);

    return p==q;
}

int main()
{
    init();
    Union(1,2);
     Union(2,3);
      Union(3,4);
       Union(4,5);
       if(isFriend(1,5))
       {
           cout<<"They are friend!"<<endl;
       }
       else
       {
           cout<<"They are not friend!"<<endl;
       }

    return 0;
}
