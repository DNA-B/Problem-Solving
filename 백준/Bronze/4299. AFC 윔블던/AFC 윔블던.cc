#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    int x, y, a, b;

    cin >> x >> y;

    a = (x + y) / 2;
    b = (x - y) / 2;

    if ((x + y) % 2 != 0 || (x - y) % 2 != 0)
        cout << -1 << '\n';
    else
    {
        if (a >= 0 && b >= 0)
        {
            if (a >= b)
                cout << a << ' ' << b << '\n';
            else
                cout << b << ' ' << a << '\n';
        }
        else
            cout << -1 << '\n';
    }

	return 0;
}