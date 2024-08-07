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
int N, M;
int res = INT_INF;
int d[401][401];
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		fill(d[i] + 1, d[i] + (N + 1), INT_INF);
		d[i][i] = 0;
	}

	while (M--) {
		int a, b, c;
		cin >> a >> b >> c;
		d[a][b] = c; // 중복 간선 X
	}

	for (int k = 1; k <= N; k++) {
		for (int st = 1; st <= N; st++) {
			for (int en = 1; en <= N; en++) {
				if (d[st][en] > d[st][k] + d[k][en])
					d[st][en] = d[st][k] + d[k][en];
			}
		}
	}

	for (int st = 1; st <= N; st++) {
		for (int en = 1; en <= N; en++) {
			if (st == en) continue;
			res = min(res, d[st][en] + d[en][st]);
		}
	}

	cout << (res == INT_INF ? -1 : res);
	return 0;
}