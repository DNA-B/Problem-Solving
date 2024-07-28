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
int N, M, x, y;
pair<int, int> wanted_star[201], star[1001];
map<pair<int, int>, int> m; // { {x 차이, y 차이}, cnt }
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		wanted_star[i] = { x, y };
	}

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		star[i] = { x, y };
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++)
			m[{ star[j].X - wanted_star[i].X, star[j].Y - wanted_star[i].Y }]++;
	}

	for (auto item : m) {
		if (item.Y == M) {
			cout << item.X.first << " " << item.X.second;
			break;
		}
	}

	return 0;
}