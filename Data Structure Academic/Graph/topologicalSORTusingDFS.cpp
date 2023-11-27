#include<bits/stdc++.h>
using namespace std;

vector<int> v[100000];
vector<int> res;
int vis[100003];

void dfs(int node)
{
    vis[node] = 1;
    for (int i = 0; i < v[node].size(); i++)
    {
        int child = v[node][i];
        if (!vis[child])
        {
            dfs(child);
        }
    }
    res.push_back(node);
}

int main()
{
    int n, m;
    cout << "Vertices: ";
    cin >> n;
    cout << "Edge: ";
    cin >> m;
    int x, y;

    while (m--)
    {
        cin >> x >> y;
        v[x].push_back(y);
    }

    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            dfs(i);
        }
    }

    cout<<"Topological sort ordering: ";
    for(int i=res.size()-1;i>=0;i--)
    {
        cout<<res[i]<<" ";
    }
    return 0;
}
