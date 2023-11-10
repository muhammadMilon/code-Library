#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1000];
int vis[1000];

void bfs(int s, int n)
{
    // Initialize the 'vis' array to mark all nodes as unvisited (0).
    for (int i = 0; i < n; i++)
    {
        vis[i] = 0;
    }

    // Create a queue for BFS and push the starting node 's' into it.
    queue<int> q;
    q.push(s);
    vis[s] = 1; // Mark the starting node as visited.

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        // Traverse all adjacent nodes of 'u' and mark them as visited.
        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i];
            if (vis[v] == 0)
          {
                vis[v] = 1;
                q.push(v);
          }
        }
    }
}

int main()
{
    int n, m; // 'n' is the number of nodes, 'm' is the number of edges.
    cin >> n >> m;

    // Build the adjacency list by reading 'm' edges.
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int s; // Starting node for BFS.
    cin >> s;

    bfs(s, n);

    // Print the BFS result.
    cout << "BFS Result starting from node " << s << ": ";
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 1)
        {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}
