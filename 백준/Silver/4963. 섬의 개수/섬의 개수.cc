#include <bits/stdc++.h>

using namespace std;

int board[51][51];
int vis[51][51];
int n, m;
int dx[8] = { -1, 1, 0, 0,  1, -1, 1, -1}; // 상하좌우대각
int dy[8] = { 0, 0, -1 ,1 , 1, -1, -1, 1 };

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int land = 0;

    while (1)
    {
        queue<pair<int, int>> q;

        cin >> n >> m;

        if (n == 0 || m == 0) return 0;

        for (int i = 0; i < m; i++)
        {
            fill(board[i], board[i] + n, 0);
            fill(vis[i], vis[i] + n, 0);
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> board[i][j];
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 0 || vis[i][j] != 0)
                    continue;

                land++;
                vis[i][j] = 1;
                q.push({ i,j });

                while (!q.empty())
                {
                    auto cur = q.front();
                    q.pop();

                    for (int dir = 0; dir < 8; dir++)
                    {
                        int nx = cur.second + dx[dir]; // 방향 설정
                        int ny = cur.first + dy[dir];

                        if (nx < 0 || nx >= n || ny >= m || ny < 0)
                            continue; // 범위 밖일 경우
                        if (vis[ny][nx] != 0 || board[ny][nx] == 0)
                            continue; // 이미 방문

                        vis[ny][nx] = 1;
                        q.push({ ny,nx });
                    }
                }
            }
        }
        cout << land << "\n";
        land = 0;
    }
   
    return 0;
}