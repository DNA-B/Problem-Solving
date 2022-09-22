#include <bits/stdc++.h>

using namespace std;

int board[501][501] = { 0 };
bool vis[501][501] = { 0 }; // 방문 여부(1 = 방문, 0 = x)
int n, m; // n = 행, m = 열
int dx[4] = { 1,-1,0,0 }; // 상하좌우
int dy[4] = { 0,0,-1,1 }; 

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int max_area = 0;
    int area = 0;
    int num = 0;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) // 시작점 찾기
        {
            if (board[i][j] == 0 || vis[i][j] == 1) continue;
            
            // 시작점 발견
            queue<pair<int, int> > Q; // 새로운 그림 시작점
            vis[i][j] = 1;
            Q.push({ i, j });

            num++; // 그림++
            area = 0; // 면적 초기화

            while (!Q.empty()) // 그림 하나 Flood Fill
            {
                pair<int, int> cur = Q.front();
                Q.pop();
                area++;

                for (int dir = 0; dir < 4; dir++) 
                { // 상하좌우 4칸
                    int nx = cur.first + dx[dir]; // 방향 설정
                    int ny = cur.second + dy[dir]; 

                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 밖일 경우 넘어감
                    if (vis[nx][ny] == 1 || board[nx][ny] != 1) continue; // 이미 방문 or 1이 아닐 경우

                    vis[nx][ny] = 1; // 방문 설정
                    Q.push({ nx,ny });
                }
            }
            max_area = max(max_area, area); // 면적 비교
        }
    }
    
    cout << num << "\n" << max_area;

    return 0;
}