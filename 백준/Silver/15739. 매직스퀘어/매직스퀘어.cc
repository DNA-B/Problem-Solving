#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAX 4e9

using namespace std;

int N;
int arr[101][101];
map<int, int> m;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];

            if (m[arr[i][j]] == 1)
            {
                cout << "FALSE";
                return 0;
            }

            m[arr[i][j]] = 1;
        }
    }

    int sum = N * (pow(N, 2) + 1) / 2;
    int s_row = 0, s_col = 0, s_dia1 = 0, s_dia2 = 0;
    for (int i = 0; i < N; i++)
    {
        s_row = s_col = 0;
        s_dia1 += arr[i][i]; // 오른쪽 대각선 '\' 
        s_dia2 += arr[i][N - i - 1]; // 왼쪽 대각선 -> '/'


        for (int j = 0; j < N; j++)
            s_row += arr[i][j];

        for (int j = 0; j < N; j++)
            s_col += arr[j][i];

        if (s_row != sum || s_col != sum)
        {
            cout << "FALSE";
            return 0;
        }
    }

    if (s_dia1 != sum || s_dia2 != sum)
        cout << "FALSE";
    else
        cout << "TRUE";

    return 0;
}
