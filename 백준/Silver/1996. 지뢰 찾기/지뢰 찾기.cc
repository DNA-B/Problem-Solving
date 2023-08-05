#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int N;
char board[1001][1001];
char ans[1001][1001];
int nx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int ny[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] != '.')
            {
                ans[i][j] = '*';
                continue;
            }

            int cnt = 0;
            for (int dir = 0; dir < 8; dir++)
            {
                int dx = i + nx[dir];
                int dy = j + ny[dir];

                if (dx < 0 || dx >= N || dy < 0 || dy >= N)
                    continue;

                if (board[dx][dy] != '.')
                    cnt += board[dx][dy] - '0';
            }

            if (cnt >= 10)
                ans[i][j] = 'M';
            else
                ans[i][j] = cnt + '0';
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << ans[i][j];
        }
        cout << "\n";
    }

    return 0;
}
