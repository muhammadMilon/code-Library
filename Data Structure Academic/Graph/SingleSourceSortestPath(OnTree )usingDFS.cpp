#include<bits/stdc++.h>
using namespace std;

vector<int>v[10000];
int vis[1000],dis[10000];

void dfs(int node,int d)
{
    vis[node]=1;
    dis[node]=d;
    for(auto child: v[node])
    {
        if(vis[child]==0)
        {
            dfs(child,d+1);
        }
    }
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
    cout<<"Enter a Source: ";
    int x;
    cin>>x;
    dfs(x,0);
    for(int i=1;i<=n;i++)
    {
        cout<<x<<" -> "<<i<<" = "<<dis[i]<<endl;
    }
    return 0;
}
