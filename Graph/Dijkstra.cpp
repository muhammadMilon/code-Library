#include<bits/stdc++.h>
#define mx 1005
#define inf 9999999999999

using namespace std;

struct node
{
    int val;
    int cost;
};

vector<node>G[mx];
bool vis[mx];
int dis[mx];

void reset()
{
    for(int i=0; i<inf; i++)
    {
        G[i].clear();
        vis[i]=0;
        dis[i]=inf;
    }
}

class cmp
{
public:

    bool operator()(node &A,node &B)
    {
        if(A.cost>B.cost)
        {
            return true;
        }
        return false;
    }
};

void Dijkstra(int source)
{
    priority_queue<node,vector<node>,cmp>pq;
    pq.push({source,0});

    while(!pq.empty())
    {
        node cur=pq.top();
        pq.pop();

        int val=cur.val;
        int cost=cur.cost;

        if(vis[val]==1)
            continue;

        dis[val]=cost;
        vis[val]=1;

        for(int i=0; i<G[val].size(); i++)
        {
            int nxt=G[val][i].val;
            int nxtCost=G[val][i].cost;

            if(vis[nxt]==0)
            {
                pq.push({nxt,cost+nxtCost});
            }
        }
    }
}

int main()
{
    reset();
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        G[u].push_back({v,w});
    }
    int source;
    cin>>source;
    Dijkstra(source);

    for(int i=1;i<=m;i++)
    {
        cout<<"Node :"<<i<<"Distance :";
        if(dis[i]==inf)
        {
            cout<<"INF"<<endl;
        }
        else
        {
            cout<<dis[i]<<endl;
        }
    }
    return 0;
}
