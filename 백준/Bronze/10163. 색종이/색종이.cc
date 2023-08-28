#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int N;
int board[101][101];
int ans[101];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        int x, y, w, h;

        cin >> x >> y >> w >> h;

        for (int j = x; j < x + w; j++)
            for (int k = y; k < y + h; k++)
                board[j][k] = i;
    }

    for (int i = 0; i < 101; i++)
        for (int j = 0; j < 101; j++)
            ans[board[i][j]] += 1;

    for (int i = 1; i <= N; i++)
        cout << ans[i] << "\n";

    return 0;
}