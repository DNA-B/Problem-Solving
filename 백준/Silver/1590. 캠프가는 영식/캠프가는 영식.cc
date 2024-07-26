#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define INF 0x3f3f3f3f
#define LLINF 1e18
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N, T;
tuple<int, int, int> bus[51];
set<int> t;
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> T;

	for (int i = 0; i < N; i++) {
		int S, I, C;
		cin >> S >> I >> C;

		while (C--) {
			t.insert(S);
			S += I;
		}
	}

	auto it = t.lower_bound(T);
	cout << (it == t.end() ? -1 : *it - T);
	return 0;
}