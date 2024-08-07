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
int T;
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> T;

	while (T--) {
		int N, M, R = 0, W = 0;
		string res = "";

		cin >> N >> M;

		for (int i = 0; i < M; i++) {
			int r, w;
			cin >> r >> w;
			R = max(R, r);
			W = max(W, w);
		}

		if (R + W > N) {
			cout << "IMPOSSIBLE\n";
			continue;
		}

		R += (N - (W + R));
		while (R--) res += 'R';
		while (W--) res += 'W';

		cout << res << "\n";
	}

	return 0;
}