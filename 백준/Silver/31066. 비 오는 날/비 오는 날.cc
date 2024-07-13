#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define BOUND 200005
#define INF 0x3f3f3f3f
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int T, N, M, K;
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> T;

	while (T--) {
		cin >> N >> M >> K;

		int cnt = 0;
		int a = N, b = M, c = 0, d = 0;

		if (N > 1 && M == 1 && K == 1) {
			cout << -1 << "\n";
			continue;
		}

		while (c != N) {
			if (d == 0) {
				c = min(N, c + (b * K));
				d = b;
				a = max(0, a - (b * K));
				b = 0;
			}
			else if (b == 0) {
				a = a + 1;
				b = d;
				c = c - 1;
				d = 0;
			}
			cnt++;
		}
		cout << cnt << "\n";
	}

	return 0;
}