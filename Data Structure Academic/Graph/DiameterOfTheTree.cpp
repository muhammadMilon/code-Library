#include<bits/stdc++.h>
using namespace std;

vector<int>v[100000];
int vis[10000],dis[10000];
int mx= INT_MIN,nod;

void dfs(int node,int d)
{
    vis[node]=1;
    dis[node]=d;

    if(dis[node]>mx)
    {
        mx=dis[node];
        nod=node;
    }
    for(int child : v[node])
    {
        if(vis[child]==0)
        {
            dfs(child,dis[node]+1);
        }
    }
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
    dfs(1,0);

    for (int i = 1; i <= n; i++)
    {
        vis[i] = 0;
    }
    mx = INT_MIN;

    dfs(nod,0);
    cout<<mx<<endl;

    return 0;
}
