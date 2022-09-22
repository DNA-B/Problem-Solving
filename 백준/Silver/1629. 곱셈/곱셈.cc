#include <bits/stdc++.h>

using namespace std;

long long powMod(long long a, long long b, long long c)
{
    long long val;
    if (b == 1)
        return a % c;

    val = powMod(a, b / 2, c); // b/2가 k라면 b는 2k다.
    val = val * val % c;

    if (b % 2 == 0) // 짝수라면 2k > k이므로 바로 반환
        return val;
    else // 홀수라면 2k+1 > k이기 때문에 a를 한 번 더 곱해준다.
        return val * a % c;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long a, b, c;

    cin >> a >> b >> c;
    cout << powMod(a, b, c);

    return 0;
}