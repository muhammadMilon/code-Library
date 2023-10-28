#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10000];
int vis[1003];

void dfs(int node)
{
    vis[node] = 1;
    for (auto child : adj[node])
    {
        if (vis[child] == 0)
        {
            dfs(child);
        }
    }
}

int main()
{
    int n, e;
    cout << "Vertices: ";
    cin >> n;
    cout << "Edges: ";
    cin >> e;
    int x, y;
    while (e--)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            cnt++;
            dfs(i);
        }
    }
    cout <<"The Number of Counting Connected Component(s) in Graph: "<< cnt << endl;
    return 0;
}
