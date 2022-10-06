#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a1, a2, a3, a4, a5;
	int b1, b2, b3, b4, b5;
	int a, b;

	cin >> a1 >> a2 >> a3 >> a4 >> a5;
	cin >> b1 >> b2 >> b3 >> b4 >> b5;

	a = (a1 * 6) + (a2 * 3) + (a3 * 2) + (a4 * 1) + (a5 * 2);
	b = (b1 * 6) + (b2 * 3) + (b3 * 2) + (b4 * 1) + (b5 * 2);

	cout << a << " " << b;

	return 0;
}