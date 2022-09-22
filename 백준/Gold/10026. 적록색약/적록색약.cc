#include <bits/stdc++.h>
#define IO ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

queue<pair<int, int>> q;
string board[101];
int vis[101][101];
int n, m;
int dx[4] = { -1, 1, 0, 0 }; // 상하좌우
int dy[4] = { 0, 0, -1 ,1 };


/*
- 1과 0이 아닌 문자로 주어진 보드 문제
- 시작점을 구별하여 vis를 1로 만들기 애매하다.
- for로 하나씩 돌면서 시작점을 판별하고 바로 BFS를 실행한다.
*/

int main() 
{
    IO;
    
    string str;
    int rep;
    int normal = 0;
    int rg = 0;

    cin >> rep;
    n = rep;
    m = n;

    for (int i = 0; i < rep; i++)
    {
        cin >> str;
        board[i] = str;
    }

    for (int i = 0; i < rep; i++) // 일반인
    {
        for (int j = 0; j < rep; j++)
        {
            if (vis[i][j] != 0) continue;

            normal++;
            vis[i][j] == 1;
            q.push({ i,j });

            while (!q.empty())
            {
                auto cur = q.front();
                q.pop();

                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.first + dx[dir]; // 방향 설정
                    int ny = cur.second + dy[dir];
                    if (nx < 0 || nx >= n || ny >= m || ny < 0) continue; // 범위 밖일 경우
                    if (board[nx][ny] != board[cur.first][cur.second] || vis[nx][ny] == 1) continue; // 이미 방문

                    vis[nx][ny] = 1;
                    q.push({ nx,ny });
                }
            }
        }
    }

    queue<pair<int, int>> q;
    int vis[101][101] = { {0} };

    for (int i = 0; i < rep; i++) // 적록색약
    {
        for (int j = 0; j < rep; j++)
        {
            if (vis[i][j] != 0) continue;

            rg++;
            vis[i][j] == 1;
            q.push({ i,j });

            while (!q.empty())
            {
                auto cur = q.front();
                q.pop();

                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.first + dx[dir]; // 방향 설정
                    int ny = cur.second + dy[dir];
                    if (nx < 0 || nx >= n || ny >= m || ny < 0) continue; // 범위 밖일 경우
                    if (board[cur.first][cur.second] == 'G' || board[cur.first][cur.second] == 'R') // 적록색약일 경우 R = G이므로 따로 처리해준다.
                    {
                        if (board[nx][ny] == 'B' || vis[nx][ny] == 1) continue;
                        
                        vis[nx][ny] = 1;
                        q.push({ nx,ny });
                        continue;
                    }
                    if (board[nx][ny] != board[cur.first][cur.second] || vis[nx][ny] == 1) continue;

                    vis[nx][ny] = 1;
                    q.push({ nx,ny });
                }
            }
        }
    }
    
    cout << normal << " " << rg;

    return 0;
}