#include <bits/stdc++.h>

using namespace std;

int board[1001][1001] = { 0 };
int dist[1001][1001] = { 0 }; // 방문 + 날짜
int n, m; // n = 행, m = 열
int dx[4] = { 1,-1,0,0 }; // 상하좌우
int dy[4] = { 0,0,-1,1 };


/* 
- 익은 토마토(시작점)가 여러 개이고 그 위치에서부터 주변 토마토들이 익는다.
- 그러므로 익은 토마토(시작점)들을 입력할 때 구별하여 큐에 넣어준다.
- 그러면 익은 토마토를 기준으로 BFS를 하므로 동시에 퍼져나가는 듯하게 구현 된다.
*/

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int, int> > Q;
    int res = 0;

    cin >> m >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];

            if (board[i][j] == 1) Q.push({ i, j }); // 익은 토마토는 시작점
            if (board[i][j] == 0) dist[i][j] = -1; // -1은 아직 방문 x
        }
    }

    while (!Q.empty()) // Q 요소는 익은 토마토 = 출발점
    {
        pair<int, int> cur = Q.front();
        Q.pop();

        for (int dir = 0; dir < 4; dir++)
        { // 상하좌우 4칸
            int nx = cur.first + dx[dir]; // 방향 설정
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 밖일 경우 넘어감
            if (dist[nx][ny] != -1) continue; // 이미 방문했을 경우

            dist[nx][ny] = dist[cur.first][cur.second] + 1; // 하루(+1) 증가
            Q.push({ nx, ny });
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (dist[i][j] == -1) // 안 익은 토마토가 있음에도 방문하지 않은 상태 
            {
                cout << -1;
                return 0;
            }
            res = max(res, dist[i][j]);
        }
    }

    cout << res;

    return 0;
}