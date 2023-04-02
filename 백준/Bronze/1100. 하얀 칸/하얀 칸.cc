#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    char board[10][10];
    int ans = 0;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cin >> board[i][j];

            if (board[i][j] == 'F')
            {
                if (i % 2 == 0) // 짝 -> 짝
                {
                    if (j % 2 == 0)
                        ans++;
                }
                else // 홀 -> 짝
                {
                    if (j % 2 != 0)
                        ans++;
                }
            }
        }
    }

    cout << ans;

    return 0;
}