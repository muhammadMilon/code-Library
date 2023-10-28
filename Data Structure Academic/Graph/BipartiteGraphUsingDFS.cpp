#include<bits/stdc++.h>
using namespace std;

vector<int>v[10000];
int vis[1000],col[10000];

bool dfs(int node,int c)
{
    vis[node]=1;
    col[node]=c;
    for(auto child: v[node])
    {
        if(vis[child]==0)
        {
           if(dfs(child,c^1)==false)
           {
               return false;
           }
           else
           {
               if(col[node]==col[child])
               {
                   return false;
               }
           }
        }
    }
    return true;
}

int main()
{
    int n,e;
    cin>>n>>e;
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    bool ans=dfs(1,1);
    if(ans)
    {
        cout<<"The Graph is Bipartite.";
    }
    else
    {
         cout<<"The Graph is not Bipartite.";
    }
    return 0;
}
