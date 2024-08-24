#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

/******** MACRO ********/
#define PI 3.1415926535897932
#define MOD 1000000007
#define INT_INF 0x3f3f3f3f
#define LL_INF 1e18
#define ll long long
#define ull unsigned long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int C, S, T;
/***********************/

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> C;

	while (C--) {
		queue<tuple<int, int, int>> q; // {s, t, cnt}
		cin >> S >> T;
		q.push({ S, T, 0 });

		while (!q.empty()) {
			auto [s, t, cnt] = q.front(); q.pop();

			if (s > t)
				continue;
			if (s == t) {
				cout << cnt << '\n';
				break;
			}

			q.push({ s * 2, t + 3, cnt + 1 });
			q.push({ s + 1, t, cnt + 1 });
		}
	}

	return 0;
}