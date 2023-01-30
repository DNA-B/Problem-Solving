#include <bits/stdc++.h>

using namespace std;

char v[52][52];
char copy_v[52][52];
int n;
int max_value = -1;

void find_max()
{
    int cnt = 1;

    for (int i = 0; i < n; i++)
    { // row
        for (int p = 0; p < 2; p++)
        { // 오른쪽, 아래
            cnt = 1;

            for (int j = 1; j <= n; j++)
            { // col
                if (p == 0)
                {
                    if (v[i][j] == v[i][j - 1])
                    {
                        cnt++;
                    }
                    else
                    {
                        max_value = max(max_value, cnt);
                        cnt = 1;
                    }
                }
                else
                {
                    if (v[j][i] == v[j - 1][i])
                    {
                        cnt++;
                    }
                    else
                    {
                        max_value = max(max_value, cnt);
                        cnt = 1;
                    }
                }
            }
            max_value = max(max_value, cnt);
        }
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    { // row
        for (int j = 0; j < n - 1; j++)
        { // col
            if (v[i][j] != v[i][j + 1])
            {
                swap(v[i][j], v[i][j + 1]);
                find_max();
                swap(v[i][j], v[i][j + 1]);
            }

            if (v[j][i] != v[j + 1][i])
            {
                swap(v[j][i], v[j + 1][i]);
                find_max();
                swap(v[j][i], v[j + 1][i]);
            }
        }
    }
   
    cout << max_value;

    return 0;
}