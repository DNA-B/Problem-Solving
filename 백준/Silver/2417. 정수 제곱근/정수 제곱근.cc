#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define BOUND 1001
#define ll long long
#define first X
#define second Y

using namespace std;

ll N;

ll binary_search(ll n) {
	ll lo = -1, hi = LLONG_MAX;

	while (lo + 1 < hi) {
		// (lo + hi)하면서 long long 범위 넘어갈 수 있으므로 unsigned
		unsigned ll mid = (lo + hi) / 2;

		if ((mid * mid) == n)
			return mid;

		if ((mid * mid) < n)
			lo = mid;
		else
			hi = mid;
	}

	return hi;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	cout << binary_search(N);

	return 0;
}