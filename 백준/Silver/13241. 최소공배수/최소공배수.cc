#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

long long A, B;
long long g, l;

long long get_gcd(long long big, long long small)
{
    int a = big, b = small, c = a % b;

    while (c != 0)
    {
        a = b;
        b = c;
        c = a % b;
    }

    return b;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> A >> B;

    g = get_gcd(max(A, B), min(A, B));
    l = (A * B) / g;

    cout << l;

    return 0;
}
