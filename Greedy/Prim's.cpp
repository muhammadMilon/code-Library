#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
vector<pii> v[1000];
const int inf = 1e9;
int n; //number of vertices
int s; //starting vertices

struct node
{
    int u,cost;
    node() {};
    node(int _u, int _cost)
    {
        u=_u;
        cost=_cost;
    }
};

bool operator<(node a,node b)
{
    return a.cost>b.cost;
}

priority_queue<node> pq;

int cost[100];
int taken[100];

void prim()
{
    for(int i=0; i<n; i++)
    {
        cost[i]=inf;
        taken[i]=0;
    }
    cost[s]=0;
    pq.push(node(s,0));
    int ans=0;
    while(!pq.empty())
    {
        node x=pq.top();
        pq.pop();

        if(taken[x.u])
        {
            continue;
        }
        taken[x.u]=1;
        ans+=x.cost;

        for(pii p : v[x.u])
        {
            int vertex = p.first;
            int weight = p.second;
            if(!taken[vertex] && weight < cost[vertex])
            {
                pq.push(node(vertex, weight));
                cost[vertex] = weight;
            }
        }
    }
    printf("Cost of MST = %d\n",ans);
}

int main()
{

    prim();

    return 0;
}
