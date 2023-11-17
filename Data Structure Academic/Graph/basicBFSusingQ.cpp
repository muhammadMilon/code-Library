#include<bits/stdc++.h>
using namespace std;

vector<int> v[100000];
int vis[10000];
int dis[10000];
vector<int> bfsTraversal;

void bfs(int node)
{
    queue<int> q;
    q.push(node);
    vis[node] = 1;
    dis[node] = 1;
    while (!q.empty())
    {
        int cur = q.front();
        bfsTraversal.push_back(cur);
        q.pop();
        for (int child : v[cur])
        {
            if (vis[child] == 0)
            {
                dis[child] = dis[cur] + 1;
                vis[child] = 1;
                q.push(child);
            }
        }
    }
}

int main()
{
    int n, e, x, y;
    cin >> n >> e;
    while (e--)
    {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    bfs(1);

    cout << "BFS Traversal: ";
    for (int node : bfsTraversal)
    {
        cout << node << " ";
    }
    cout << endl;

    for (int i = 1; i <= n; ++i)
    {
        cout << "Distance of node " << i << " from the starting node: " << dis[i] << endl;
    }

    return 0;
}
