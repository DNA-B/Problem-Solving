#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAX 4e9

using namespace std;

int N, M;
char board[601][601];
int vis[601][601];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
queue<pair<int, int>> q;
int ans = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];

            if (board[i][j] == 'I')
            {
                q.push({ i, j }); 
                vis[i][j] = 1;
            }
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
            if (board[nx][ny] == 'X')
                continue;
            if (vis[nx][ny] != 0)
                continue;

            if (board[nx][ny] == 'P')
                ans++;

            q.push({ nx, ny });
            vis[nx][ny] = 1;
        }
    }

    if (ans == 0)
        cout << "TT";
    else
        cout << ans;

    return 0;
}
