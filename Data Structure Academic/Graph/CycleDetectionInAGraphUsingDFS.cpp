#include<bits/stdc++.h>
using namespace std;

vector<int>v[10000];
int vis[1000];

bool dfs(int node,int par)
{
    vis[node]=1;
    for(int child: v[node])
    {
        if(vis[child]==0)
        {
            if(dfs(child,node))
            {
                return true;
            }
        }
        else
        {
            if(child!=par)
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int n,e;
    cin>>n>>e;
    while(e--)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    bool ans=dfs(1,-1);
    if(ans)
    {
        cout<<"The Graph is Cycled."<<endl;
    }
    else
    {
        cout<<"The Graph is not Cycled."<<endl;
    }
}
