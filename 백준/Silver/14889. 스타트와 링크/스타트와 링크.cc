#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int board[21][21];
bool is_used[21];
int N;
int ans = INF;

void solve(int cur, int nxt)
{
    if (cur == N / 2)
    {
        int start = 0, link = 0;

        for (int i = 1; i <= N; i++)
        {
            for (int j = i + 1; j <= N; j++)
            {
                if (is_used[i] == true && is_used[j] == true)
                    start += board[i][j] + board[j][i];
                if (is_used[i] == false && is_used[j] == false)
                    link += board[i][j] + board[j][i];
            }
        }

        ans = min(ans, abs(start - link));
        return;
    }

    for (int i = nxt; i < N; i++)
    {
        if (!is_used[i])
        {
            is_used[i] = true;
            solve(cur + 1, i + 1);
            is_used[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> board[i][j];

    solve(0, 1);
    cout << ans;

    return 0;
}
