#include <bits/stdc++.h>

using namespace std;

int H, M, N;
int board[101][101][101];
int vis[101][101][101];
int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, -1, 1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, -1, 1 };

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<tuple<int, int, int>> q;
    int res = 0;

    cin >> M >> N >> H;

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                cin >> board[i][j][k];

                if (board[i][j][k] == 1) // 익은 토마토
                    q.push({i, j, k});
                if (board[i][j][k] == 0) // 안 익은 토마토
                    vis[i][j][k] = -1;
                if (board[i][j][k] == -1) // 토마토 없는 위치
                    vis[i][j][k] = -2;
                
            }
        }
    }

    while (!q.empty())
    {
        tuple<int, int, int> cur = q.front();
        q.pop();

        for (int dir = 0; dir < 6; dir++)
        {
            int nx = get<0>(cur)+ dx[dir];
            int ny = get<1>(cur) + dy[dir];
            int nz = get<2>(cur) + dz[dir];

            if (nx < 0 || nx >= H)
                continue;
            if (ny < 0 || ny >= N)
                continue;
            if (nz < 0 || nz >= M)
                continue;

            if (vis[nx][ny][nz] != -1 || board[nx][ny][nz] == -1)
                continue;

            vis[nx][ny][nz] = vis[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
            q.push({ nx, ny, nz });
        }
    }

    for (int i = 0; i < H; i++) // 안 익은 토마토 남아있나 사
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                if (vis[i][j][k] == -1)
                {
                    cout << -1;
                    return 0;
                }
                res = max(res, vis[i][j][k]);
            }
        }
    }

    cout << res;

    return 0;
}