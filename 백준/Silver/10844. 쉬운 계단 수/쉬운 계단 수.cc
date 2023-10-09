#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAX 4e9
#define MOD 1000000000

using namespace std;

int N;
int ans = 0;
int mem[101][10];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    fill(mem[1] + 1, mem[1] + 10, 1);

    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (j == 9)
                mem[i][j] = mem[i - 1][j - 1] % MOD;
            else if (j == 0)
                mem[i][j] = mem[i - 1][j + 1] % MOD;
            else
                mem[i][j] = (mem[i - 1][j - 1] + mem[i - 1][j + 1]) % MOD;

            mem[i][j] %= MOD;
        }
    }

    for (int i = 0; i < 10; i++)
        ans = (ans + mem[N][i]) % MOD;

    cout << ans;

    return 0;
}
