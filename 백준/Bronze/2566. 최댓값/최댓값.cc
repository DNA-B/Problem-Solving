#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> v(10);
int max_value = -1;
int x, y;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for (int i = 1; i < 10; i++)
        v[i].resize(10, 0);

    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            cin >> v[i][j];

            if (v[i][j] > max_value)
            {
                max_value = v[i][j];
                x = i;
                y = j;
            }
        }
    }

    cout << max_value << "\n" << x << " " << y;

    return 0;
}