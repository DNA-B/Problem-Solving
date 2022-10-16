#include <bits/stdc++.h>

using namespace std;

string board[1000];
int vis[1000][1000][2]; // x, y, 벽 부쉈는지 여부

int n, m;
int dx[4] = { -1, 1, 0, 0 }; // 상하좌우
int dy[4] = { 0, 0, -1 ,1 };

int bfs()
{
    queue<pair<pair<int, int>, pair<int, int>>> q;

    q.push({ { 0,0 }, {0,1} }); // {x,y}, {벽 부순 여부, 거리}
    vis[0][0][0] = 1;

    while (!q.empty())
    {
        auto cur = q.front();
        int is_crash = cur.second.first;
        int cnt = cur.second.second;

        q.pop();

        if ((cur.first.first == n - 1) && (cur.first.second == m - 1)) // 도착
            return cnt;

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first.first + dx[dir]; // 방향 설정
            int ny = cur.first.second + dy[dir];

            if (nx < 0 || nx >= n || ny >= m || ny < 0)
                continue; // 범위 밖일 경우

            if (board[nx][ny] == '1' && is_crash == 0) // 벽 있는데 안 부쉈으면
            {
                vis[nx][ny][is_crash + 1] = 1;
                q.push({ {nx,ny},{is_crash + 1, cnt + 1} });
            }
            else if (board[nx][ny] == '0' && vis[nx][ny][is_crash] == 0) // 벽 없으면
            {
                vis[nx][ny][is_crash] = 1;
                q.push({ { nx,ny }, {is_crash, cnt + 1} });
            }
        }
    }
    
    // 도착 못함
    return -1;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> board[i];
    }

    cout << bfs();

    return 0;
}
