#include<bits/stdc++.h>

using namespace std;

vector<int> parent, Rank;

void makeSet(int u)
{
    parent[u] = u;
    Rank[u] = 0;
}

int Find(int u)
{
    if (u == parent[u])
        return u;
    return parent[u] = Find(parent[u]);
}

void Union(int u, int v)
{
    u = Find(u);
    v = Find(v);
    if (u != v)
    {
        if (Rank[u] < Rank[v])
            swap(u,v);
        parent[v] = u;
        if (Rank[u] == Rank[v])
            Rank[u]++;
    }
}

struct Edge
{
    int u, v, weight;
    bool operator<(Edge const& other)
    {
        return weight < other.weight;
    }
};

int MST(int n, vector<Edge>& edges)
{
    int cost = 0;
    //vector<Edge> mstEdges;

    parent.resize(n);
    Rank.resize(n);
    for (int i = 0; i < n; i++)
        makeSet(i);

    sort(edges.begin(), edges.end());

    for (Edge e : edges)
    {
        if (Find(e.u) != Find(e.v))
        {
            cost += e.weight;
           // mstEdges.push_back(e);
            Union(e.u, e.v);
        }
    }
    return cost;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    int totalWeight = MST(n, edges);
    cout << totalWeight << endl;

    return 0;
}
