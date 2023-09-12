#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true)
    {
        int x, y;

        cin >> x >> y;

        if (x == 0 && y == 0)
            break;

        if (y % x == 0)
            cout << "factor\n";
        else if (x % y == 0)
            cout << "multiple\n";
        else
            cout << "neither\n";
    }

    return 0;
}
