#include<bits/stdc++.h>
using namespace std;

vector<int>v[100000];
int vis[10000],subtree[10000];

int dfs(int node)
{
    vis[node]=1;
    int cnt=1;

    for(int child : v[node])
    {
        if(vis[child]==0)
        {
          cnt+=dfs(child);
        }
    }
    subtree[node]=cnt;
    return cnt;
}

int main()
{
    int n,e,x,y;
    cin>>n>>e;

    while(e--)
    {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1);

    for (int i = 1; i <= n; i++)
    {
        vis[i] = 0;
    }

    for(int i=1;i<=n;i++)
    {
        cout<<"The SubTree of node "<<i<<" is "<<subtree[i]<<endl;
    }

    return 0;
}
