#include <bits/stdc++.h>

using namespace std;

string qt[65];

void q_tree(int n, int r, int l)
{
    if (n == 1) // base condition
    {
        cout << qt[r][l];
        return;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (qt[r + i][l + j] != qt[r][l])
            { /* 첫 색을 기준으로 다른 색이 나올 경우 
              (n / 2) 크기의 4사분면으로 분할한다. */

                cout << '(';
                q_tree(n / 2, r, l); // 1사분면
                q_tree(n / 2, r, l + (n / 2)); // 2사분면
                q_tree(n / 2, r + (n / 2), l); // 3사분면
                q_tree(n / 2, r + (n / 2), l + (n / 2)); // 4사분면
                cout << ')';

                return;
            }
        }
    }

    cout << qt[r][l]; // 반복문에서 나왔으므로 다른 색이 없다.
    return;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> qt[i];
    }

    q_tree(n, 0, 0); // 시작 좌표 (0, 0)

    return 0;
}