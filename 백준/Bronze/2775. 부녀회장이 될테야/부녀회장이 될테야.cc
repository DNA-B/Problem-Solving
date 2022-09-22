#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int apart[15][15] = { 0 };
    int t, k, n;

    cin >> t;

    for (int i = 0; i < 15; i++) // 1호
    {
        apart[i][1] = 1;
    }

    for (int i = 1; i < 15; i++) // 첫줄
    {
        apart[0][i] = i;
    }

    for (int i = 1; i < 15; i++)
    {
        for (int j = 2; j < 15; j++)
        {
            apart[i][j] = apart[i][j - 1] + apart[i - 1][j];
        }
    }

    while (t--)
    {
        cin >> k >> n;
        cout << apart[k][n] << "\n";
    }
    return 0;
}