#include <bits/stdc++.h>

using namespace std;

int board[101][101];
int vis[101][101];
int temp[101][101];
int n;
int dx[4] = { -1, 1, 0, 0}; // 상하좌우
int dy[4] = { 0, 0, -1 ,1};


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int safe = 0;
    int cnt = 0;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i <= 100; i++) // 최대 높이 까지 모두 확인
    {
        queue<pair<int, int>> q;
        copy(&vis[0][0], &vis[0][0] + (101 * 101), &temp[0][0]);

        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (board[j][k] <= i) // i[비의 높이]보다 작거나 같으면 물이 참
                    temp[j][k] = 1;
            }
        }

        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (temp[j][k] != 0)
                    continue;

                cnt++;
                temp[j][k] = 1;
                q.push({ j,k });

                while (!q.empty())
                {
                    auto cur = q.front();
                    q.pop();

                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.second + dx[dir]; // 방향 설정
                        int ny = cur.first + dy[dir];

                        if (nx < 0 || nx >= n || ny >= n || ny < 0)
                            continue; // 범위 밖일 경우
                        if (temp[ny][nx] != 0)
                            continue; // 이미 방문

                        temp[ny][nx] = 1;
                        q.push({ ny,nx });
                    }
                }
            }
        }
        safe = max(safe, cnt);
        cnt = 0;
    }

    cout << safe;

    return 0;
}