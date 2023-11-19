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
            if (arr[i][j] == 'X')
            {
                if (cnt >= 2)
                    garo++;

                cnt = 0;
            }
            else
                cnt++;
        }

        if (cnt >= 2)
            garo++;
    }

    for (int i = 0; i < N; i++)
    {
        int cnt = 0;

        for (int j = 0; j < N; j++)
        {
            if (arr[j][i] == 'X')
            {
                if (cnt >= 2)
                    sero++;

                cnt = 0;
            }
            else
                cnt++;
        }

        if (cnt >= 2)
            sero++;
    }

    cout << garo << " " << sero;

    return 0;
}
