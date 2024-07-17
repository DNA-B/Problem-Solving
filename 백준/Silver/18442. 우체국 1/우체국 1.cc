#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define BOUND 25
#define INF 0x3f3f3f3f
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int V, P;
ll L, res = LLONG_MAX;
ll town[BOUND];
vector<ll> tmp(BOUND), po(BOUND);
/***********************/

void solve(int prev, int cnt) {
	if (cnt == P) {
		ll dist = 0;

		for (int i = 0; i < V; i++) {
			ll min_dist = LLONG_MAX;
			for (int j = 0; j < P; j++) {
				if (town[i] == tmp[j]) {
					min_dist = 0;
					break;
				}
				min_dist = min({ min_dist, abs(town[i] - tmp[j]), L - abs(town[i] - tmp[j]) });
			}
			dist += min_dist;
		}

		if (res > dist)
			res = dist, po = tmp;

		return;
	}

	for (int i = prev + 1; i < V; i++) {
		tmp[cnt] = town[i];
		solve(i, cnt + 1);
	}
}

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> V >> P >> L;

	for (int i = 0; i < V; i++)
		cin >> town[i];

	solve(-1, 0);

	cout << res << "\n";
	for (int i = 0; i < P; i++)
		cout << po[i] << " ";

	return 0;
}