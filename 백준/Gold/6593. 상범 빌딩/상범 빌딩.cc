#include <bits/stdc++.h>

using namespace std;

int L, R, C;
int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, -1, 1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, -1, 1 };
char board[32][32][32];
int vis[31][31][31];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (1)
    {
        cin >> L >> R >> C;

        if (L == 0 && R == 0 && C == 0)
            break;

        fill(&board[0][0][0], &board[31][31][32], 0);
        fill(&vis[0][0][0], &vis[30][30][31], 0);
        queue<tuple<int, int, int>> q;
        bool escape = false;

        for (int i = 0; i < L; i++)
        {
            for (int j = 0; j < R; j++)
            {
                for (int k = 0; k < C; k++)
                {
                    cin >> board[i][j][k];

                    if (board[i][j][k] == 'S')
                    {
                        vis[i][j][k] = 0;
                        q.push({ i,j,k });
                    }
                }
            }
        }

        while (!q.empty())
        {
            tuple<int, int, int> cur = q.front();
            q.pop();

            for (int dir = 0; dir < 6; dir++)
            {
                int nx = get<0>(cur) + dx[dir];
                int ny = get<1>(cur) + dy[dir];
                int nz = get<2>(cur) + dz[dir];

                if (nx < 0 || nx >= L)
                    continue;
                if (ny < 0 || ny >= R)
                    continue;
                if (nz < 0 || nz >= C)
                    continue;

                if (vis[nx][ny][nz] != 0 || board[nx][ny][nz] == '#')
                    continue;
                
                if (board[nx][ny][nz] == 'E')
                {
                    cout << "Escaped in " << vis[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1 << " minute(s).\n";
                    escape = true;
                    break;
                }

                vis[nx][ny][nz] = vis[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
                q.push({ nx, ny, nz });
            }

            if (escape)
                break;

        }

        if (!escape)
            cout << "Trapped!\n";

    }

    return 0;
}
