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
int N, M, res = INT_MAX;
tuple<int, int, int> t[101];
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		t[i] = { a, b, c };
	}

	sort(t, t + N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int cnt = 0;
			for (int k = 0; k < N; k++) {
				auto [a, b, c] = t[k];
				if ((b <= get<1>(t[i])) && (c <= get<2>(t[j]))) cnt++;
				if (cnt == M) {
					res = min(res, get<1>(t[i]) + get<2>(t[j]) + a);
					break;
				}
			}
		}
	}

	cout << res;
	return 0;
}