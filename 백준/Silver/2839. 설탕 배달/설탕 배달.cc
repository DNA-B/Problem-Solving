#include <bits/stdc++.h>

using namespace std;

int mem[5001];
int n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    mem[3] = 1;
    mem[5] = 1;

    cin >> n;

    for (int i = 6; i <= n; i++)
    {
        if (mem[i - 5] == 0 && mem[i - 3] != 0)
            mem[i] += mem[i - 3] + 1;
        else if (mem[i - 5] != 0)
            mem[i] += mem[i - 5] + 1;
    }

    if (mem[n] == 0)
        cout << -1;
    else
        cout << mem[n];

    return 0;
}
