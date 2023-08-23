#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define IDX 1000
using namespace std;

int N;
int board[101][101];
int ans = 0;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int x, y;
        
        cin >> x >> y;

        for (int j = x; j < x + 10; j++)
        {
            for (int k = y; k < y + 10; k++)
            {
                if (board[j][k] == 1)
                    continue;

                board[j][k] = 1;
            }
        }
    }

    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            ans += board[i][j];

    cout << ans;

    return 0;
}