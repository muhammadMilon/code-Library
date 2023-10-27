#include<bits/stdc++.h>
using namespace std;

vector<int> v[10000];
bool vis[1003];

void dfs(int node)
{
    vis[node] = true;
    cout << node;

    bool first = true;
    for (int i = 0; i < v[node].size(); i++)
    {
        int child = v[node][i];
        if (!vis[child])
        {
            if (first)
            {
                cout << " -> ";
                first = false;
            }
            dfs(child);
        }
    }
}

int main()
{
    int n, m;
    cout << "Vertices: ";
    cin >> n;
    cout << "Edge: ";
    cin >> m;
    int x, y;
    int minNode = INT_MAX;

    while (m--)
    {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
        minNode = min(minNode, min(x, y));
    }

    cout << "Depth First Search: ";
    dfs(minNode);
    return 0;
}
