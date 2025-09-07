#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

//========= MACRO =========//
#define PI 3.1415926535897932
#define INF 0x3f3f3f3f
#define LL_INF 1e18
#define ll long long
#define X first
#define Y second
//=========================//

//======= VARIABLEs =======//
int N, M, en = -1;
int cows[1005], T[1005];
vector<int> adj[1005];
priority_queue<pair<int, int>,
	vector<pair<int, int>>,
	greater<>> pq;
//=========================//

void race() {
	T[1] = cows[1];
	en = T[1];
	pq.push({ T[1], 1 });

	while (!pq.empty()) {
		auto [cur_t, cow] = pq.top();
		pq.pop();

		if (cur_t > T[cow])
			continue;

		for (int nxt : adj[cow]) {
			int nxt_t = cur_t + cows[nxt];
			if (cur_t + cows[nxt] < T[nxt]) {
				T[nxt] = nxt_t;
				en = max(en, T[nxt]);
				pq.push({ nxt_t, nxt });
			}
		}
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> cows[i] >> M;
		for (int a, j = 1; j <= M; j++) {
			cin >> a;
			adj[i].push_back(a);
		}
	}

	fill(T, T + N + 1, INF);
	race();
	cout << en;
}