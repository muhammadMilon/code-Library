#include<bits/stdc++.h>

using namespace std;

struct edge
{
    int u, v, w;
    edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
    bool operator<(const edge& other) const
    {
        return w < other.w;
    }
};

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
            swap(u, v);
        parent[v] = u;
        if (Rank[u] == Rank[v])
            Rank[u]++;
    }
}

int mst(int n, vector<edge>& edges)
{
    int cost = 0;
    parent.resize(n + 1);
    Rank.resize(n + 1);
    for (int i = 1; i <= n; i++)
        makeSet(i);

    sort(edges.begin(), edges.end());

    for (edge e : edges)
    {
        if (Find(e.u) != Find(e.v))
        {
            cost += e.w;
            Union(e.u, e.v);
        }
    }
    return cost;
}

int main()
{

    int  n, m;
    cin >> n >> m;

    vector<edge> edges;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back(edge(a, b, c));
    }

    int totalWeight = mst(n, edges);
    cout << totalWeight<< endl;

    return 0;
}
