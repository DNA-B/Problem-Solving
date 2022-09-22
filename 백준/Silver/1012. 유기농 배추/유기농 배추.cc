#include <bits/stdc++.h>

using namespace std;

int board[51][51];
int vis[51][51];
int n, m;
int dx[4] = { -1, 1, 0, 0 }; // 상하좌우
int dy[4] = { 0, 0, -1 ,1 };

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int, int>> q;
    int t_case;
    int bug = 0;
    int bechu;
    int bx, by;

    cin >> t_case;

    while (t_case--)
    {
        cin >> m >> n >> bechu;

        for (int i = 0; i < n; i++)
        {
            fill(board[i], board[i] + m, 0);
            fill(vis[i], vis[i] + m, 0);
        }

        while (bechu--)
        {
            cin >> bx >> by; // 입력받는 x가 가로이고 y가 세로이다.
            board[by][bx] = 1;
        }

        for (int i = 0; i < n; i++) // flood fill 방식
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] != 1 || vis[i][j] == 1) continue;

                q.push({ i,j });
                bug++;

                while (!q.empty())
                {
                    auto cur = q.front();
                    q.pop();

                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.first + dx[dir]; // 방향 설정
                        int ny = cur.second + dy[dir];
                        if (nx < 0 || nx >= n || ny >= m || ny < 0) continue; // 범위 밖일 경우
                        if (vis[nx][ny] != 0 || board[nx][ny] != 1) continue; // 이미 방문
                       
                        vis[nx][ny] = 1;
                        q.push({ nx,ny });
                    }
                }
            }
        }
        cout << bug << "\n";
        bug = 0;
    }
   
    return 0;
}