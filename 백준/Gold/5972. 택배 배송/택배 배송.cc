#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
/****** VARIABLEs ******/
int N, M;
int d[50001];
vector<pair<int, int>> adj[50001];
priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> pq;
/***********************/
int dijk(int st) {
	d[st] = 0;pq.push({ 0, st });
	while (!pq.empty()) {
		auto [cur_cost, cur] = pq.top();pq.pop();
		if (d[cur] != cur_cost)continue;
		if (cur == N)break;
		for (auto [nxt_cost, nxt] : adj[cur]) {
			if (d[nxt] > d[cur] + nxt_cost) {
				d[nxt] = d[cur] + nxt_cost;
				pq.push({ d[nxt], nxt });
			}}}
	return d[N];}
int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	cin >> N >> M;
	fill(d + 1, d + (N + 1), INF);
    int u, v, cost;
	for (int i = 0; i < M; i++) {
		cin >> u >> v >> cost;
		adj[u].push_back({ cost,  v });
		adj[v].push_back({ cost,  u });
	}
	cout << dijk(1);
	return 0;}