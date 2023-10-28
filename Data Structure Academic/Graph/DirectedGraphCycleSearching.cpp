#include<bits/stdc++.h>
using namespace std;

vector<int>v[10000];
int vis[1000];

bool dfs(int node)
{
    vis[node]=1;
    for(int child: v[node])
    {
        if(vis[child]==0)
        {
            if(dfs(child))
            {
                return true;
            }
        }
        else
        {
            if(vis[child]==1)
            {
                return true;
            }
        }
    }
    vis[node]=2;
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
        v[x].push_back(y); //Since ,this is a directed graph
    }
    bool ans=dfs(1);
    if(ans)
    {
        cout<<"Cycle Found in this Graph."<<endl;
    }
    else
    {
        cout<<"Cycle is not Found in this Graph."<<endl;
    }
    return 0;
}
