#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

/*
N = 1일 때, 1
N = 2일 때, 5
N = 3일 때, 9
N = 4일 때, 13
길이는 (4 * (N - 1)) + 1
좌표는 +2씩 증가
*/

int N;
char board[501][501];

void counting_star(int n, int x, int y)
{
    if (n == 1)
    {
        board[x][y] = '*';
        return;
    }

    int len = 4 * (n - 1) + 1;

    // 위, 아래
    for (int j = y; j < y + len; j++)
    {
        board[x][j] = '*';
        board[x + (len - 1)][j] = '*';
    }

    // 좌, 우
    for (int i = x; i < x + len; i++)
    {
        board[i][y] = '*';
        board[i][y + (len - 1)] = '*';
    }

    counting_star(n - 1, x + 2, y + 2);
    return;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    fill(&board[0][0], &board[500][501], ' ');

    counting_star(N, 0, 0);

    for (int i = 0; i < 4 * (N - 1) + 1; i++)
    {
        for (int j = 0; j < 4 * (N - 1) + 1; j++)
        {
            cout << board[i][j];
        }
        cout << '\n';
    }

    return 0;
}
