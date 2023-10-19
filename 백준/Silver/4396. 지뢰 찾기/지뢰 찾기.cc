#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAX 4e9
#define MOD 1000000000

using namespace std;

int N;
string board[10];
char ans[10][10];
bool game_over = false;
int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { -1, 0, 1, -1, 1, -1, 1, 0 };

void open_bomb()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (board[i][j] == '*')
                ans[i][j] = '*';
}

int find_bomb(int x, int y)
{
    int cnt = 0;

    for (int dir = 0; dir < 8; dir++)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || nx >= N || ny < 0 || ny >= N)
            continue;
        if (board[nx][ny] == '*')
            cnt++;
    }

    return cnt;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
        fill(ans[i], ans[i] + N, '.');

    for (int i = 0; i < N; i++)
        cin >> board[i];

    for (int i = 0; i < N; i++)
    {
        char tmp;
        for (int j = 0; j < N; j++)
        {
            cin >> tmp;

            if (tmp == 'x')
            {
                if (board[i][j] == '*')
                {
                    if (!game_over)
                    {
                        game_over = true;
                        open_bomb();
                    }
                }
                else
                    ans[i][j] = find_bomb(i, j) + '0';
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << ans[i][j];
        cout << "\n";
    }

    return 0;
}
