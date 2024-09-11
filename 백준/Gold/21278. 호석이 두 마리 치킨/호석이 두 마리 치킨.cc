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
int N, M;
int mx = -1, mn = INT_MAX, h1, h2;
int d[105][105];
/***********************/

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		fill(d[i] + 1, d[i] + (N + 1), INT_INF);
		d[i][i] = 0;
	}

	int st, en;
	while (M--) {
		cin >> st >> en;
		d[st][en] = d[en][st] = 1;
	}

	for (int k = 1; k <= N; k++) {
		for (int st = 1; st <= N; st++) {
			for (int en = 1; en <= N; en++) {
				if (d[st][en] > d[st][k] + d[k][en])
					d[st][en] = d[st][k] + d[k][en];
			}
		}
	}

	for (int c1 = 1; c1 <= N; c1++) {
		for (int c2 = 1; c2 <= N; c2++) {
			if (c1 == c2)
				continue;

			int tmp = 0;
			for (int k = 1; k <= N; k++)
				tmp += min(d[k][c1] + d[c1][k], d[k][c2] + d[c2][k]);

			if (mn > tmp) {
				mn = tmp;
				h1 = c1;
				h2 = c2;
			}
		}
	}

	int total = 0;
	for (int i = 1; i <= N; i++)
		total += min(d[i][h1] + d[h1][i], d[i][h2] + d[h2][i]);

	cout << h1 << ' ' << h2 << ' ' << total;
	return 0;
}