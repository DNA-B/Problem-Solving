#include <bits/stdc++.h>

using namespace std;

int R, C;
int total_w = 0, total_s = 0;
int wolf = 0, sheep = 0;
char board[252][252];
int vis[251][251];
int dx[4] = { -1, 1, 0, 0 }; // 상하좌우
int dy[4] = { 0, 0, -1 ,1 };
queue<pair<int, int>> q;

// . 이면 bfs -> wolf, sheep 비교해서 둘 중 하나 0으로 만들고 total 변경

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> board[i][j];
        }
    }
    
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (vis[i][j] != 0 || board[i][j] == '#')
                continue;

            vis[i][j] = 1;
            q.push({ i,j });

            if (board[i][j] == 'o')
                sheep++;
            else if (board[i][j] == 'v')
                wolf++;

            while (!q.empty())
            {
                auto cur = q.front();
                q.pop();

                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];

                    if (nx < 0 || nx >= R || ny < 0 || ny >= C)
                        continue;
                    if (vis[nx][ny] != 0 || board[nx][ny] == '#')
                        continue;

                    if (board[nx][ny] == 'o')
                        sheep++;
                    else if (board[nx][ny] == 'v')
                        wolf++;

                    vis[nx][ny] = 1;
                    q.push({ nx,ny });
                }
            }

            // 늑대, 양 판단
            total_w += sheep <= wolf ? wolf : 0;
            total_s += sheep > wolf ? sheep : 0;
            wolf = 0;
            sheep = 0;
        }
    }

    cout << total_s << " " << total_w;

    return 0;
}