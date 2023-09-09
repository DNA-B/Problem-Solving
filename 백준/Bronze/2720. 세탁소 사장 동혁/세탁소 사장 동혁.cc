#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int T;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    while (T--)
    {
        int c;
        int q = 0, d = 0, n = 0, p = 0;

        cin >> c;

        q += c / 25;
        c -= 25 * (c / 25);

        d += c / 10;
        c -= 10 * (c / 10);

        n += c / 5;
        c -= 5 * (c / 5);

        p += c;
        c = 0;

        cout << q << " " << d << " " << n << " " << p << "\n";
    }

    return 0;
}
