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
ll L, A;
int N, K;
queue<pair<ll, ll>> q; // 위치, 거리
set<ll> vis;
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> L >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> A;
		q.push({ A, 0 });
		vis.insert(A);
	}

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		cout << cur.Y << "\n";
		K--;

		if (K == 0)
			break;

		for (auto dir : { 1, -1 }) {
			ll nx = cur.X + dir;

			if (nx < 0 || nx > L)
				continue;
			if (vis.find(nx) != vis.end())
				continue;

			vis.insert(nx);
			q.push({ nx, cur.Y + 1 });
		}
	}

	return 0;
}