#include <bits/stdc++.h>

using namespace std;

string board[101];
int dist[101][101] = { 0 }; // 방문 + 거리
int n, m; // n = 행, m = 열
int dx[4] = { 1,-1,0,0 }; // 상하좌우
int dy[4] = { 0,0,-1,1 };

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int, int> > Q;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> board[i];
        fill(dist[i], dist[i] + m, -1);
    }

    dist[0][0] = 0;
    Q.push({ 0, 0 });

    while (!Q.empty()) // 미로 끝까지
    {
        pair<int, int> cur = Q.front();
        Q.pop();

        for (int dir = 0; dir < 4; dir++)
        { // 상하좌우 4칸
            int nx = cur.first + dx[dir]; // 방향 설정
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 밖일 경우 넘어감
            if (dist[nx][ny] >= 0 || board[nx][ny] != '1') continue; // 이미 방문 or 1이 아닐 경우

            dist[nx][ny] = dist[cur.first][cur.second] + 1; // 전 좌표 +1 값 기록
            Q.push({ nx, ny });
        }
    }
    cout << dist[n - 1][m - 1] + 1; // {0, 0}의 거리가 0이니까 +1해서 출력

    return 0;
}