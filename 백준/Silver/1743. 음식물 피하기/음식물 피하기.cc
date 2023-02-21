#include <bits/stdc++.h>

using namespace std;

int ans = 0;
int trash_size = 0;
int n, m, k;
int st, en;
int board[101][101];
int vis[101][101];
int dx[4] = { -1, 1, 0, 0 }; // 상하좌우
int dy[4] = { 0, 0, -1 ,1 };
queue<pair<int, int>> q;

void bfs()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (board[i][j] == 0 || vis[i][j] != 0)
                continue;

            vis[i][j] = 1;
            q.push({ i,j });

            while (!q.empty())
            {
                auto cur = q.front();
                q.pop();
                trash_size++;

                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];

                    if (nx < 0 || nx > n || ny > m || ny < 0)
                        continue;
                    if (vis[nx][ny] != 0 || board[nx][ny] == 0)
                        continue;

                    vis[nx][ny] = 1;                
                    q.push({ nx,ny });
                }
            }

            ans = ans < trash_size ? trash_size : ans;
            trash_size = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    for (int i = 0; i < k; i++)
    {
        cin >> st >> en;
        board[st][en] = 1;
    }
    
    bfs();

    cout << ans;

    return 0;
}