#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define BOUND 1001
#define INF 0x3f3f3f3f
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int T, N, M;
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> T;

	while (T--) {
		vector<int> v;

		cin >> N;
		v.resize(N);

		for (int& x : v)
			cin >> x;

		cin >> M;
		sort(v.begin(), v.end());

		for (int x, i = 0; i < M; i++) {
			cin >> x;
			cout << (binary_search(v.begin(), v.end(), x) ? 1 : 0) << "\n";
		}
	}

	return 0;
}