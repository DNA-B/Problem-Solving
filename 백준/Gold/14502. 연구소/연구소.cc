#include <bits/stdc++.h>

using namespace std;

int board[10][10]; // 원본
int b_tmp1[10][10]; // 벽 세울 보드
int b_tmp2[10][10]; // 바이러스 퍼트릴 보드

int n, m;
int dx[4] = { -1, 1, 0, 0 }; // 상하좌우
int dy[4] = { 0, 0, -1 ,1 };

int cnt = 0;
int result = -1;

void copy_arr(int(*arr)[10], int(*tmp)[10])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            tmp[i][j] = arr[i][j];
        }
    }
}

void bfs()
{
    queue<pair<int, int>> q;
    copy_arr(b_tmp1, b_tmp2);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (b_tmp2[i][j] == 2)
            {
                q.push({ i, j });
            }

            while (!q.empty())
            {
                auto cur = q.front();
                q.pop();

                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.first + dx[dir]; // 방향 설정
                    int ny = cur.second + dy[dir];

                    if (nx < 0 || nx >= n || ny >= m || ny < 0)
                        continue; // 범위 밖일 경우
                    
                    if (b_tmp2[nx][ny] == 0) // 안전구역일 경우 바이러스 퍼짐
                    {
                        b_tmp2[nx][ny] = 2;
                        q.push({ nx,ny });
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    { // 안전구역 확인
        for (int j = 0; j < m; j++)
        {
            if (b_tmp2[i][j] == 0)
                cnt++;
        }
    }

    result = max(result, cnt); // 최댓값 갱신
    cnt = 0;
}

void wall(int cur)
{
    if (cur == 3)
    {
        bfs(); // 벽 3개 다 세움
        return;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (b_tmp1[i][j] == 0)
            {
                b_tmp1[i][j] = 1; // 벽 cur + 1개
                wall(cur + 1);
                b_tmp1[i][j] = 0; // 벽 cur개
            }
        }
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

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
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 0)
            {
                copy_arr(board, b_tmp1);

                b_tmp1[i][j] = 1; // 벽 1개
                wall(1);
                b_tmp1[i][j] = 0; // 벽 0개
            }
        }
    }
    cout << result;

    return 0;
}
