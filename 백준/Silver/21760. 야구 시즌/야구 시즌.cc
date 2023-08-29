#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int T;
long long N, M, K, D;
long long B;

long long get_total(long long n, long long m, long long k)
{
    return n * m * (k * (m - 1) + m * (n - 1)) / 2;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    while (T--)
    {
        cin >> N >> M >> K >> D;

        long long tmp = get_total(N, M, K);
        B = D / tmp;

        if (B < 1)
            cout << -1 << "\n";
        else
            cout << B * tmp << "\n";
    }
    

    return 0;
}