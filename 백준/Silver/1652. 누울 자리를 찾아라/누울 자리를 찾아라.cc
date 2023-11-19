#include <bits/stdc++.h>

using namespace std;

int N;
char arr[102][102];
int garo = 0, sero = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> arr[i][j];

    for (int i = 0; i < N; i++)
    {
        int cnt = 0;

        for (int j = 0; j < N; j++)
        {
            cnt = arr[i][j] == '.' ? cnt + 1 : 0;
            garo = (cnt == 2) ? garo + 1 : garo;
        }
    }

    for (int i = 0; i < N; i++)
    {
        int cnt = 0;

        for (int j = 0; j < N; j++)
        {
            cnt = arr[j][i] == '.' ? cnt + 1 : 0;
            sero = (cnt == 2) ? sero + 1 : sero;
        }
    }

    cout << garo << " " << sero;

    return 0;
}
