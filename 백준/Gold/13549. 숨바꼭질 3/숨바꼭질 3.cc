#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/******** MACRO ********/
#define BOUND 100001
#define MOD 1'000'000'007
#define ll long long
#define X first
#define Y second
/***********************/

using namespace std;

/****** VARIABLEs ******/
const int INF = 0x3f3f3f3f;
int N, K;
int d[BOUND]; // 거리
vector<pair<int, int>> adj[BOUND]; // {비용, 정점 번호}
priority_queue<pair<int, int>,
	vector<pair<int, int>>,
	greater<pair<int, int>>> pq;
/***********************/

int main() {
	cin.tie(0)->sync_with_stdio(0);
	// freopen("input.txt", "r", stdin);

	cin >> N >> K;
	fill(d, d + BOUND, INF);

	adj[N].push_back({ 0, 2 * N });
	adj[N].push_back({ 1, N + 1 });
	adj[N].push_back({ 1, N - 1 });

	d[N] = 0;
	pq.push({ d[N],N });

	while (!pq.empty()) // O(ElgE), 방향 그래프 혹은 무방향 그래프, 음수 간선 X
	{
		auto cur = pq.top();
		pq.pop();

		if (d[cur.second] != cur.first) // 거리가 d에 있는 값과 다를 경우 넘어감
			continue;

		for (auto nxt : adj[cur.second]) {
			if (nxt.second < 0 || nxt.second >= BOUND)
				continue;
			if (d[nxt.second] <= d[cur.second] + nxt.first) // 이미 있던 값이 더 작을 경우 pass
				continue;

			d[nxt.second] = d[cur.second] + nxt.first;
			adj[nxt.second].push_back({ 0, 2 * nxt.second });
			adj[nxt.second].push_back({ 1, nxt.second + 1 });
			adj[nxt.second].push_back({ 1, nxt.second - 1 });
			pq.push({ d[nxt.second],nxt.second });
		}
	}

	cout << d[K];

	return 0;
}