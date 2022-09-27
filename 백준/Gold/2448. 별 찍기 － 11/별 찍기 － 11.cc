#include <bits/stdc++.h>

using namespace std;

int cnt = 0;
int x, y;
vector<pair<int, int>> v;

char arr[3100][6200];

void counting_star(int n, int x, int y)
{
    if (n == 3) // 2의 거듭제곱을 다 나눴다면 base condition은 3이다.
    {
        /*
                *
               * *
              *****
        */
        arr[x][y] = '*';
        arr[x + 1][y - 1] = '*';
        arr[x + 1][y + 1] = '*';
        for (int i = y - 2; i <= y + 2; i++)
            arr[x + 2][i] = '*';
        
        return;
    }

    // 3 * 2^n이므로 삼각형을 세 부분으로 나눠서 보낸다. 
    // 3개를 나누고 2로 분할한다
    counting_star((n / 2), x, y);
    counting_star((n / 2), x + (n / 2), y - (n / 2));
    counting_star((n / 2), x + (n / 2), y + (n / 2));
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    x = 0;
    y = n - 1;

    counting_star(n, x, y);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 * n - 1; j++)
        {
            if (arr[i][j] == '*')
                cout << arr[i][j];
            else
                cout << " ";
        }
        cout << "\n";
    }

    return 0;
}