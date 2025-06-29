#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_set>
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
int N, M, X, Y;
int d[1005];
vector<int> seq;
vector<pair<int, int>> adj[1005];
priority_queue<pair<int, int>,
	vector<pair<int, int>>,
	greater<pair<int, int>>> pq;
//=========================//

void dijk(int st) {
	d[st] = 0;
	pq.push({ d[st], st });

	while (!pq.empty()) {
		auto [cost, cur] = pq.top();
		pq.pop();

		if (d[cur] != cost)
			continue;

		for (auto& [nxt_cost, nxt] : adj[cur]) {
			if (d[nxt] > d[cur] + nxt_cost) {
				d[nxt] = d[cur] + nxt_cost;
				pq.push({ d[nxt], nxt });
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

	cin >> N >> M >> X >> Y;

	for (int a, b, c, i = 0; i < M; i++) {
		cin >> a >> b >> c;
		adj[a].push_back({ c, b });
		adj[b].push_back({ c, a });
	}

    fill(d, d + 1005, INF);
	dijk(Y);

	for (int i = 0; i < N; i++) {
		if (i == Y)
			continue;
		if (d[i] == INF || 2 * d[i] > X) { // 갈 수 없는 지역
			cout << -1;
			exit(0);
		}

		seq.push_back(d[i]);
	}

	sort(seq.begin(), seq.end());

	int day = 1, cur_dist = 0;
	for (int cost : seq) {
		if (cur_dist + (2 * cost) > X) { // 현재 위치에서 집으로 갔다가 다른 집을 갈 수 없는 경우
			cur_dist = 0;
			day++;
		}

		cur_dist += 2 * cost;
	}

	cout << day;
}