#include <bits/stdc++.h>

using namespace std;

int N;
int P[1001];
int mem[1001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> P[i];

    for (int i = 1; i <= N; i++)
    {
        mem[i] = P[i];

        for (int j = 1; j <= i; j++)
            mem[i] = max(mem[j] + mem[i - j], mem[i]);
    }

    cout << mem[N];

    return 0;
}
