#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    int rival = 1;
    int res;

    cin >> a >> b >> c;

    rival = b / a;
    res = 3 * rival * c;

    cout << res;

    return 0;
}