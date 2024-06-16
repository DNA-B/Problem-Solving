#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define BOUND 2002
#define MOD 1'000'000'007
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
const int INF = 0x3f3f3f3f;
int TC, N, M, T, S, G, H;
int dist_gh, min_g, min_h;
set<int> res;
vector<pair<int, int>> adj[BOUND];
/***********************/

int dijk(int st, int en) {
	int d[BOUND];
	priority_queue<pair<int, int>,
		vector<pair<int, int>>,
		greater<pair<int, int>>> pq;

	fill(d, d + BOUND, INF);
	d[st] = 0;
	pq.push({ d[st], st });

	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();

		if (d[cur.Y] != cur.first)
			continue;

		for (auto nxt : adj[cur.Y]) {
			if (d[nxt.Y] > d[cur.Y] + nxt.X) {
				d[nxt.Y] = d[cur.Y] + nxt.X;
				pq.push({ d[nxt.Y], nxt.Y });
			}
		}
	}

	return d[en];
}


int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> TC;

	while (TC--) {
		res = {};
		cin >> N >> M >> T >> S >> G >> H;

		for (auto& item : adj)
			item.clear();

		for (int a, b, d, i = 0; i < M; i++) {
			cin >> a >> b >> d;
			adj[a].push_back({ d, b });
			adj[b].push_back({ d, a });

			if ((a == G && b == H) || (a == H && b == G))
				dist_gh = d;
		}

		min_g = dijk(S, G);
		min_h = dijk(S, H);

		for (int x, i = 0; i < T; i++) {
			cin >> x;

			if (min_g < min_h) {
				if (dijk(S, x) == min_g + dist_gh + dijk(H, x)) // (s -> g -> h -> x)를 거치는 것이 최소경로인가?
					res.insert(x);
			}
			else {
				if (dijk(S, x) == min_h + dist_gh + dijk(G, x)) // (s -> h -> g -> x)를 거치는 것이 최소경로인가?
					res.insert(x);
			}
		}

		for (auto item : res)
			cout << item << " ";
		cout << "\n";
	}

	return 0;
}