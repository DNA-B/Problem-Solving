#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int arr[101][101];
int res = 0;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x1, x2, y1, y2;
    for (int i = 0; i < 4; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;

        for (int j = x1; j < x2; j++)
        {
            for (int k = y1; k < y2; k++)
            {
                if (arr[j][k] == 0)
                    arr[j][k] = 1;
                else
                    continue;
            }
        }
    }

    for (int i = 1; i <= 100; i++)
        for (int j = 1; j <= 100; j++)
            if (arr[i][j] == 1)
                res++;

    cout << res;

    return 0;
}
