#include<bits/stdc++.h>
using namespace std;

bool vis[5][5];

int dx[] = {-1, 1,  0, 0, -1, -1,  1, 1};
int dy[] = {0,  0, -1, 1, -1,  1, -1, 1};

bool valid(int x, int y)
{
    return (x >= 0 && x < 5 && y >= 0 && y < 5 && !vis[x][y]);
}

struct node
{
    int x;
    int y;
};

void bfs(int sx, int sy)
{
    queue < node > Q;
    Q.push({sx, sy});
    vis[sx][sy] = 1;

    while(!Q.empty())
    {
        int x = Q.front().x;
        int y = Q.front().y;
        Q.pop();

        for (int i = 0; i < 8; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (valid(nx, ny))
            {
                vis[nx][ny] = 1;
                Q.push({nx, ny});
            }
        }
    }
}


int main()
{
    bfs(2, 2);
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
