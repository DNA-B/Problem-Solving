#include<bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int N, M;
string board[101];
int vis[101][101];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int ans_w = 0, ans_b = 0;
queue<pair<int, int>> q;

int bfs(char team)
{
    int team_w = 1, team_b = 1;

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= M || ny < 0 || ny >= N)
                continue;
            if (vis[nx][ny] != 0)
                continue;
            if (board[nx][ny] != team)
                continue;

            if (board[nx][ny] == 'W')
                team_w++;
            else if (board[nx][ny] == 'B')
                team_b++;

            vis[nx][ny] = 1;
            q.push({ nx, ny });
        }
    }

    if (team == 'W')
        return team_w;
    else if (team == 'B')
        return team_b;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;

    for (int i = 0; i < M; i++)
        cin >> board[i];

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (vis[i][j] != 0)
                continue;

            char team = board[i][j];

            q.push({ i, j });
            vis[i][j] = 1;

            if (team == 'W')
                ans_w += pow(bfs(team), 2);
            else if (team == 'B')
                ans_b += pow(bfs(team), 2);
        }
    }

    cout << ans_w << " " << ans_b;

    return 0;
}