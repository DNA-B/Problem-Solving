#include <bits/stdc++.h>

using namespace std;

string board[1001];
int f_time[1001][1001];
int j_time[1001][1001];
int n, m; // n = 행, m = 열
int dx[4] = { 1,-1,0,0 }; // 상하좌우
int dy[4] = { 0,0,-1,1 };


/*
- 탈출 + 불 피하기 이다.
- 불이 퍼지는 속도를 먼저 구한다.
- 그 다음 불이 퍼지는 속도보다 내가 가는 속도가 작다면 이동할 수 있음을 이용한다.
- 만약 BFS를 진행하다가 전체 칸의 범위를 벗어난다면 출력한다
- BFS는 거리순으로 큐에 push되므로 범위를 벗어난 시점이 최소값이다.
*/

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int rep;
    int res = 0;
    bool possible = 0;

    cin >> rep;

    while (rep--)
    {
        queue<pair<int, int>> fire;
        queue<pair<int, int>> ji;
        res = 0;
        possible = 0;

        cin >> n >> m;

        for (int i = 0; i < m; i++)
        {
            fill(j_time[i], j_time[i] + n, 0);
            fill(f_time[i], f_time[i] + n, 0);
        }

        for (int i = 0; i < m; i++)
        {
            cin >> board[i];

            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == '*')
                {
                    fire.push({ i, j });
                    f_time[i][j] = 1;
                }

                if (board[i][j] == '@')
                {
                    ji.push({ i, j });
                    j_time[i][j] = 1;
                }

                if (board[i][j] == '.')
                {
                    f_time[i][j] = -1; // -1은 아직 방문 x
                    j_time[i][j] = -1;
                }
            }
        }

        while (!fire.empty()) // 불 DFS 부터
        {
            pair<int, int> cur = fire.front();
            fire.pop();

            for (int dir = 0; dir < 4; dir++)
            {
                int nx = cur.second + dx[dir];
                int ny = cur.first + dy[dir];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 밖
                if (f_time[ny][nx] != -1 || board[ny][nx] != '.') continue; // 이미 방문 or 갈 수 없는 곳

                f_time[ny][nx] = f_time[cur.first][cur.second] + 1;
                fire.push({ ny, nx });
            }
        }

        while (!ji.empty()) // 불의 시간을 다 구했으므로 불이 퍼지는 시간보다 작으면 지훈이 움직일 수 있다.
        {
            pair<int, int> cur = ji.front();
            ji.pop();

            for (int dir = 0; dir < 4; dir++)
            { 
                int nx = cur.second + dx[dir];
                int ny = cur.first + dy[dir];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                { // 범위를 벗어났다는 것은 탈출에 성공했다는 의미. 큐에 거리 순으로 들어가므로 최초에 탈출한 시간을 출력.
                    possible = 1;
                    res = j_time[cur.first][cur.second];
                    break;
                }
                if (j_time[ny][nx] != -1 || board[ny][nx] != '.') continue; // 이미 방문 or 갈 수 없는 곳
                if (f_time[ny][nx] != -1)
                { // 불의 발생지가 존재하며
                    if (j_time[cur.first][cur.second] + 1 >= f_time[ny][nx]) continue; // 불이 이미 퍼져있는 경우
                }
                j_time[ny][nx] = j_time[cur.first][cur.second] + 1;
                ji.push({ ny, nx });
            }
            if (possible) break;
        }
        if (possible) cout << res << "\n";
        else cout << "IMPOSSIBLE\n";
    }
    return 0;
}