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
int A, B, D;
int min_g, min_h;
bool is_g = true;
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

		for (int i = 0; i < M; i++) {
			cin >> A >> B >> D;
			adj[A].push_back({ D, B });
			adj[B].push_back({ D, A });
		}

		min_g = dijk(S, G) + dijk(G, H);
		min_h = dijk(S, H) + dijk(H, G);
		is_g = (min_g < min_h ? true : false); // g->h, h->g 중에 무엇이 더 최소경로인지

		for (int x, i = 0; i < T; i++) {
			cin >> x;

			if (is_g) {
				if (dijk(S, x) == min_g + dijk(H, x)) // g, h를 거치는 것이 최소경로인가?
					res.insert(x);
			}
			else {
				if (dijk(S, x) == min_h + dijk(G, x)) // g, h를 거치는 것이 최소경로인가?
					res.insert(x);
			}
		}

		for (auto item : res)
			cout << item << " ";
		cout << "\n";
	}

	return 0;
}