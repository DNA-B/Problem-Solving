#include <bits/stdc++.h>

using namespace std;

string board[26];
int vis[26][26];
int n, m;
int dx[4] = { -1, 1, 0, 0 }; // 상하좌우
int dy[4] = { 0, 0, -1 ,1 };
queue<pair<int, int>> q;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int zido;
    int num_house = 0;
    int danzi = 0;
    vector<int> v;

    cin >> zido;
    m = zido;
    n = zido;

    for (int i = 0; i < m; i++)
    {
        cin >> board[i];
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == '0' || vis[i][j] != 0)
                continue;

            danzi++;
            vis[i][j] = danzi;
            q.push({ i,j });

            while (!q.empty())
            {
                auto cur = q.front();
                q.pop();
                num_house++;

                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.second + dx[dir]; // 방향 설정
                    int ny = cur.first + dy[dir];

                    if (nx < 0 || nx >= n || ny >= m || ny < 0)
                        continue; // 범위 밖일 경우
                    if (vis[ny][nx] != 0 || board[ny][nx] == '0')
                        continue; // 이미 방문

                    vis[ny][nx] = danzi;
                    q.push({ ny,nx });
                }
            }

            v.push_back(num_house);
            num_house = 0;
        }
    }

    sort(v.begin(), v.end());
    cout << danzi << "\n";
    for (int item : v)
    {
        cout << item << "\n";
    }

    return 0;
}