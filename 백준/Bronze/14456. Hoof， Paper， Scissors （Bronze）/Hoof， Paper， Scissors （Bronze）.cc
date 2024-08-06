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
int N, res = 0;
vector<pair<int, int>> v;
/***********************/

void solve(int r, int s, int p) {
	int cnt = 0;
	for (auto [fi, se] : v) {
		if ((fi == r && se == s) || (fi == s && se == p) || (fi == p && se == r))
			cnt++;
	}
	res = max(res, cnt);
}


int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({ x, y });
	}

	for (int i = 1; i <= 3; i++) { // R
		for (int j = 1; j <= 3; j++) { // S
			if (j == i) continue;
			for (int k = 1; k <= 3; k++) { // P
				if (k == i || k == j) continue;
				solve(i, j, k);
			}
		}
	}

	cout << res;
	return 0;
}