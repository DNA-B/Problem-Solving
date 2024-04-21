#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define BOUND 1'000'000'000
#define ll long long
#define first X
#define second Y

using namespace std;

ll x, y, z;

bool check(int cur) { // 100 곱하면서 int 범위 넘어갈 수 있음
	ll tmp = 100 * (y + cur) / (x + cur);

	return tmp > z;
}

int binary_search() {
	int lo = 0, hi = BOUND;

	if (!check(BOUND))
		return -1;

	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;

		if (check(mid))
			hi = mid;
		else
			lo = mid;
	}

	return hi;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> x >> y;
	z = 100 * y / x;
	cout << binary_search();

	return 0;
}