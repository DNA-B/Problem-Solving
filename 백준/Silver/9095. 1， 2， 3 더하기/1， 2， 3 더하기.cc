#include <bits/stdc++.h>

using namespace std;

int mem[12] = { 0 };
int n;

int sum_123(int cur)
{
    if (cur < 4)
        return mem[cur];

    if (mem[n] != 0)
        return mem[n];
    
    mem[cur] = sum_123(cur - 1) + sum_123(cur - 2) + sum_123(cur - 3);
    return mem[cur];
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t_case = 0;
    mem[1] = 1;
    mem[2] = 2;
    mem[3] = 4;

    cin >> t_case;

    for (int i = 0; i < t_case; i++)
    {
        cin >> n;

        if (mem[n] != 0)
        {
            cout << mem[n] << '\n';
            continue;
        }

        sum_123(n);
        cout << mem[n] << '\n';
    }

    return 0;
}