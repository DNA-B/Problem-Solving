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
int N, K, cnt = 0;
queue<ll> q;
map<ll, int> vis;
multiset<ll> res;
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> L >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> A;
		cnt++;
		vis[A] = 0, res.insert(vis[A]);
		q.push(A);
	}

	while (!q.empty() || cnt < K) {
		auto cur = q.front();
		q.pop();

		for (auto dir : { 1, -1 }) {
			ll nx = cur + dir;

			if (cnt == K)
				break;
			if (nx < 0 || nx > L)
				continue;
			if (vis.find(nx) != vis.end())
				continue;

			cnt++;
			vis[nx] = vis[cur] + 1, res.insert(vis[nx]);
			q.push(nx);
		}
	}

	for (auto idx : res)
		cout << idx << "\n";

	return 0;
}