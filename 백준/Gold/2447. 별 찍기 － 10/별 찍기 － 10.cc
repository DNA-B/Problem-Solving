#include <bits/stdc++.h>

using namespace std;

int cnt = 0;
vector<pair<int, int>> v;

char arr[2300][2300] = { '\0' };

void counting_star(int n, int x, int y)
{
    if (n == 1)
    {
        arr[x][y] = '*';
        return;
    }

    for (int i = 0; i < 3; i++)
    {
        // 3, 9, 27, 81 어떤 수가 와도 총 9개의 블럭으로 이루어진다.
        for (int j = 0; j < 3; j++)
        {
            if (i == 1 && j == 1) // (1, 1)은 9개의 블럭중 5번째로 빈 공간이다.
            {
                continue;
            }
            counting_star(n / 3, (x + (n / 3) * i), (y + (n / 3) * j));
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        fill(arr[i], arr[i] + n, ' ');
    }

    counting_star(n, 0, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j];
        }
        cout << "\n";
    }

    return 0;
}