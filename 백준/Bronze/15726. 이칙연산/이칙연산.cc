#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    long long a, b, c, x, y;

    cin >> a >> b >> c;

    x = (double)(a * b) / c;
    y = ((double)a / b) * c;

    if (x > y)
        cout << x;
    else
        cout << y;

	return 0;
}