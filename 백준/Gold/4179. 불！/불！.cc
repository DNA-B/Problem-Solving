#include <bits/stdc++.h>

using namespace std;

char board[1001][1001] = { '\0' };
int f_time[1001][1001] = { 0 }; // 방문 + 날짜
int j_time[1001][1001] = { 0 };
int n, m; // n = 행, m = 열
int dx[4] = { 1,-1,0,0 }; // 상하좌우
int dy[4] = { 0,0,-1,1 };


/*
- 탈출 + 불 피하기 이다.
- 불이 퍼지는 속도를 먼저 구한다.
- 그 다음 불이 퍼지는 속도보다 내가 가는 속도가 작다면 이동할 수 있음을 이용한다.
- 마지막에 가장자리를 돌아보면서 탈출이 가능할 경우 최소 1보다 크거나 같은 값이 나온다.
- 아닐 경우는 0.
*/

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int, int>> fire;
    queue<pair<int, int>> ji;
    int res = 0;
    bool exit = true;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];

            if (board[i][j] == 'F')
            {
                fire.push({ i, j }); 
                f_time[i][j] = 1; 
                // 1로 두면 탈출을 하지 못할 경우는 0이므로 결과를 내기 수월하다.
            }

            if (board[i][j] == 'J')
            {
                ji.push({ i, j });
                j_time[i][j] = 1;
                // 1로 두면 탈출을 하지 못할 경우는 0이므로 결과를 내기 수월하다.
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
        { // 상하좌우 4칸
            int nx = cur.first + dx[dir]; // 방향 설정
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 밖일 경우
            if (f_time[nx][ny] != -1) continue; // 이미 방문 or 갈 수 없는 곳

            f_time[nx][ny] = f_time[cur.first][cur.second] + 1; // 1분(+1) 증가
            fire.push({ nx, ny });
        }
    }

    while (!ji.empty()) // 불의 시간을 다 구했으므로 불이 퍼지는 시간보다 작으면 지훈이 움직일 수 있다.
    {
        pair<int, int> cur = ji.front();
        ji.pop();

        for (int dir = 0; dir < 4; dir++)
        { // 상하좌우 4칸
            int nx = cur.first + dx[dir]; // 방향 설정
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) { // 범위를 벗어났다는 것은 탈출에 성공했다는 의미. 큐에 거리 순으로 들어가므로 최초에 탈출한 시간을 출력.
                cout << j_time[cur.first][cur.second];
                return 0;
            }
            if (j_time[nx][ny] != -1) continue; // 이미 방문 or 갈 수 없는 곳
            if (f_time[nx][ny] != -1)
            { // 불의 발생지가 존재하며
                if (j_time[cur.first][cur.second] + 1 >= f_time[nx][ny]) continue; // 불이 이미 퍼져있는 경우
            }
            j_time[nx][ny] = j_time[cur.first][cur.second] + 1; // 1분(+1) 증가
            ji.push({ nx, ny });
        }
    }

    cout << "IMPOSSIBLE"; // BFS가 끝날 때 까지 탈출을 못하면 여기로 오게 됌.

    return 0;
}