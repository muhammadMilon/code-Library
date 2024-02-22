#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

const int MAXN = 1e5 + 3;
const int INF = INT_MAX;

vector<vector<ii>> adjList;
int n, dist[MAXN], par[MAXN];

void dijkstra(int s)
{
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    fill(dist, dist+n+1, INF);

    pq.push(ii(0, s));
    dist[s] = 0;
    par[s] = -1;

    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for(auto &pr : adjList[u])
        {
            int v = pr.first, w = pr.second;

            if(dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push(ii(dist[v], v));
                par[v] = u;
            }
        }
    }
}

int main()
{
    int m;
    scanf("%d %d", &n, &m);

    adjList.resize(n+3);

    int u, v, w;

    while(m--)
    {
        scanf("%d %d %d", &u, &v, &w);
        adjList[u].push_back(ii(v, w));
        adjList[v].push_back(ii(u, w));
    }

    dijkstra(1);

    return 0;
}
