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
int N, M;
vector<int> p(1005, -1);
vector<pair<int, int>> edges;
vector<tuple<int, int, int>> adj;
//=========================//

int uf_find(int x) {
	if (p[x] < 0)
		return x;
	return p[x] = uf_find(p[x]);
}

bool uf_union(int a, int b) {
	a = uf_find(a);
	b = uf_find(b);

	if (a == b)
		return false;

	if (p[a] == p[b])
		p[a]--;
	if (p[a] < p[b])
		p[b] = a;
	else
		p[a] = b;

	return true;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> M;

	int x, y;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		adj.push_back({ 0, x, y });
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> x;
			if (i == j || i == 1 || j == 1) continue;
			adj.push_back({ x, i, j });
		}
	}

	sort(adj.begin(), adj.end());

	int cnt = 0, cost = 0;
	for (auto& [d, u, v] : adj) {
		if (!uf_union(u, v))
			continue;

		if (d != 0)
			edges.push_back({ u, v });

		cost += d;
		cnt++;

		if (cnt == N - 2) // 1번을 제외한 모든 정점이 연결되면 종료
			break;
	}

	cout << cost << ' ' << edges.size() << '\n';

	for (auto& [a, b] : edges)
		cout << a << ' ' << b << '\n';
}