#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define PI 3.1415926535897932
#define MOD 1000000007
#define INT_INF 0x3f3f3f3f
#define LL_INF 1e18
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int M, N, S;
/***********************/

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> M;

	while (M--) {
		int mx = -1;
		cin >> N >> S;
		for (int t, i = 0; i < N; i++) {
			cin >> t;
			mx = max(mx, t);
		}
		cout << ceil((mx * S) / 1000.0) << '\n';
	}

	return 0;
}