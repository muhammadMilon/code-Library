#include<bits/stdc++.h>
using namespace std;

vector<int> v[1000];
int vis[10000];

void dfs(int node)
{
    vis[node] = 1;
    for(auto child: v[node])
    {
        if(vis[child] == 0)
            dfs(child);
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    while(e--)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        if(vis[i] == 0)
        {
            cnt++;
            dfs(i);
        }
    }
    cout << cnt << endl;
    return 0;
}
