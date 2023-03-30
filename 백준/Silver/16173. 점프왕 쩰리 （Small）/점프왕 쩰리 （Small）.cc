#include<bits/stdc++.h>

using namespace std;

int N;
int board[4][4];
int vis[4][4];
queue<pair<int, int>> q;
set<string> ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
    
    vis[0][0] = 1;
    q.push({ 0, 0 });

    while (!q.empty())
    {
        int nx, ny;
        auto cur = q.front();
        q.pop();

        for (int i = 0; i < 2; i++)
        {
            if (i == 0)
            {
                nx = cur.first + board[cur.first][cur.second];
                ny = cur.second;
            }
            else
            {
                nx = cur.first;
                ny = cur.second + board[cur.first][cur.second];
            }

            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;
            if (vis[nx][ny] != 0)
                continue;
            if (nx == N - 1 && ny == N - 1)
            {
                cout << "HaruHaru";
                return 0;
            }

            vis[nx][ny] = 1;
            q.push({ nx, ny });
        }      
    }

    cout << "Hing";

    return 0;
}