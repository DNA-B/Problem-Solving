#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int N, M;
int board[1001][1001];
int vis[1001][1001];
int dx[] = {0, 1, -1, 0};
int dy[] = { 1, 0, 0, -1 };
queue<pair<int, int>> q;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    fill(&vis[0][0], &vis[N - 1][M], -1);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];

            if (board[i][j] == 2)
            {
                vis[i][j] = 0;
                q.push({ i,j });
            }
            
            if (board[i][j] == 0)
                vis[i][j] = 0;
        }
    }

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            if (vis[nx][ny] != -1)
                continue;

            vis[nx][ny] = vis[cur.first][cur.second] + 1;
            q.push({ nx, ny });
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << vis[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}