#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define BOUND 105
#define INF 0x3f3f3f3f
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
ll N, cnt = 0;
ll l = 0, r = 0;
set<ll, greater<ll>> chu = { 1, 2, 5, 10, 20, 50, 100 };
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int stone, i = 0; i < N; i++) {
		cin >> stone;

		if (i == 0)
			l += stone;
		else if (i == 1)
			r += stone;
		else {
			if (l == r)
				l += stone;
			else if (l < r)
				l += stone;
			else
				r += stone;
		}
	}

	ll sub = abs(l - r);
	while (sub != 0) {
		for (ll item : chu) {
			cnt += sub / item;
			sub %= item;
		}
	}

	cout << cnt;

	return 0;
}