#include <bits/stdc++.h>

using namespace std;


int board[101][101];
int vis[101][101];
int n, m;
int dx[4] = { -1, 1, 0, 0 }; // 상하좌우
int dy[4] = { 0, 0, -1 ,1 };
queue<pair<int, int>> q;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> res;

    int lx, ly, hx, hy;
    int k;
    int area = 1;
    int num = 0;

    cin >> m >> n;
    cin >> k;

    while (k--)
    {
        cin >> lx >> ly >> hx >> hy;

        for (int i = ly; i < hy; i++)
        {
            for (int j = lx; j < hx; j++)
            {
                board[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 1 || vis[i][j] != 0) continue;

            num++;
            vis[i][j] = 1;
            q.push({ i,j });

            while (!q.empty())
            {
                auto cur = q.front();
                q.pop();

                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.second + dx[dir]; // 방향 설정
                    int ny = cur.first + dy[dir];
                    if (nx < 0 || nx >= n || ny >= m || ny < 0) continue; // 범위 밖일 경우
                    if (vis[ny][nx] != 0 || board[ny][nx] == 1) continue; // 이미 방문
                   
                    vis[ny][nx] = 1;
                    area++;
                    q.push({ ny,nx });
                }
            }
            res.push_back(area);
            area = 1;
        }
    }

    sort(res.begin(), res.end());

    cout << num << "\n";
    for (int item : res)
    {
        cout << item << " ";
    }

    return 0;
}