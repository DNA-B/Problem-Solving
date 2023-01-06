#include <bits/stdc++.h>

using namespace std;

long long a, b, c; // 고정비용, 가변비용, 노트북가격

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> c;

    if (b >= c)
    {
        cout << -1;
        return 0;
    }

    cout << (long long)(a / (c - b)) + 1;

    return 0;
}