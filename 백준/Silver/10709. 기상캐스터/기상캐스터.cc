#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int H, W;
char board[101][101];
int ans[101][101];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
       
    cin >> H >> W;

    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            cin >> board[i][j];

    for (int i = 0; i < H; i++)
    {
        int cloud_idx = -1;
        for (int j = 0; j < W; j++)
        {
            if (board[i][j] == 'c')
            {
                cloud_idx = j;
                ans[i][j] = 0;
                continue;
            }

            if (cloud_idx == -1)
                ans[i][j] = -1;
            else
                ans[i][j] = j - cloud_idx;
        }
    }

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
            cout << ans[i][j] << " ";
        cout << "\n";
    }

    return 0;
}