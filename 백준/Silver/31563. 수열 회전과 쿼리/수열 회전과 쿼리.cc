#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

/******** MACRO ********/
#define INT_INF 0x3f3f3f3f
#define LL_INF 1e18
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N, Q;
ll psum[200005];
/***********************/


int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> Q;

	for (int i = 1; i <= N; i++) {
		cin >> psum[i];
		psum[i] += psum[i - 1];
	}

	int cur = 0;
	while (Q--) {
		int order, k;
		cin >> order;

		switch (order) {
			case 1:
				cin >> k;
				cur -= k;
				cur = (cur + N) % N;
				break;
			case 2:
				cin >> k;
				cur += k;
				cur = (cur + N) % N;
				break;
			case 3:
				int l, r;
				cin >> l >> r;
				l = (l - 1 + cur) % N;
				r = (r - 1 + cur) % N;
				if (r >= l) cout << psum[r + 1] - psum[l] << "\n";
				else cout << psum[N] - (psum[l] - psum[r + 1]) << "\n";
				break;
		}
	}

	return 0;
}