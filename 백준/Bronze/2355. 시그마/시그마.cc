#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    long long x, y, start, end;
    long long res;

    cin >> x >> y;

    start = min(x, y);
    end = max(x, y);

    res = ( (start + end) * (end - start + 1) / 2);

    cout << res;

    return 0;
}