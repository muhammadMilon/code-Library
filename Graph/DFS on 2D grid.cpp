#include<bits/stdc++.h>
using namespace std;

bool vis[5][5];

int dx[] = {-1, 1,  0, 0, -1, -1,  1, 1};
int dy[] = {0,  0, -1, 1, -1,  1, -1, 1};

bool valid(int x, int y)
{
    return (x >= 0 && x < 5 && y >= 0 && y < 5 && !vis[x][y]);
}

void dfs(int x, int y)
{
    if (vis[x][y]) return;
    
    vis[x][y] = 1;

    for (int i = 0; i < 8; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (valid(nx, ny))
        {
            dfs(nx, ny);
        }
    }
}


int main()
{
    dfs(2, 2);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << vis[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
