#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define BOUND 1'000'000'000
#define ll long long
#define first X
#define second Y

using namespace std;

ll x, y, z;
int ans, win_rate;

int check(ll x, ll y) { // 100 곱하면서 int 범위 넘어갈 수 있음
	return 100 * y / x;
}

int binary_search(ll x, ll y, ll z) {
	int lo = 0, hi = BOUND;

	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;

		if (check(x + mid, y + mid) > z)
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

	z = check(x, y);

	if (z >= 99) { // 99%에서 변하려면 100%가 나와야하는데 100%는 모든 게임을 이겨야한다. 이미 패배가 있으므로 불가능하다.
		cout << -1;
		return 0;
	}

	cout << binary_search(x, y, z);

	return 0;
}