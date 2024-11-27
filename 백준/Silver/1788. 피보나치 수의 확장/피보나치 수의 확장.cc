#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int N;
long long mem[1000001];

void fibo(int n)
{
    mem[0] = 0;
    mem[1] = 1;

    for (int i = 2; i <= n; i++)
        mem[i] = (mem[i - 1] % 1000000000) + (mem[i - 2] % 1000000000);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    fibo(abs(N));

    if (N < 0 && N % 2 == 0)
        cout << -1 << "\n";
    else if (N == 0)
        cout << 0 << "\n";
    else
        cout << 1 << "\n";

    cout << mem[abs(N)] % 1000000000;
    return 0;
}
