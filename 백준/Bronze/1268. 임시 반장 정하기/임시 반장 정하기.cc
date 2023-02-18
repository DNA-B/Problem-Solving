#include <bits/stdc++.h>

using namespace std;

int student[1001][5];
int n;
int max_v = -1, res;
set <int> answer[1001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < 5; j++)
            cin >> student[i][j];
    
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (k == j)
                    continue;

                if (student[j][i] == student[k][i])
                    answer[k].insert(j);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        int a_size = answer[i].size();
        
        if (a_size > max_v)
        {
            max_v = a_size;
            res = i;
        }
    }

    cout << res + 1;

    return 0;
}