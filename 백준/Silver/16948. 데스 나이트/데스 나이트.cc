#include <bits/stdc++.h>

using namespace std;

int N;
int r1, r2, c1, c2;
int board[201][201];
int vis[201][201];
int dx[8] = {-2, -2, 0, 0, 2, 2};
int dy[8] = {-1, 1, -2, 2, -1, 1};
queue<pair<int, int>> q;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    cin >> r1 >> c1 >> r2 >> c2;

    for (int i = 0; i < N; i++)
        fill(vis[i], vis[i] + 201, -1);

    vis[r1][c1] = 0;
    q.push({ r1, c1 });
    
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        for (int dir = 0; dir < 8; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;
            if (vis[nx][ny] != -1)
                continue;

            vis[nx][ny] = vis[cur.first][cur.second] + 1;
            q.push({ nx, ny });
        }
    }

    if (vis[r2][c2] == -1)
        cout << -1;
    else
        cout << vis[r2][c2];

    return 0;
}