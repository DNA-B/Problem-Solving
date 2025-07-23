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

int solve() {
	int cnt = 0, cost = 0;
	for (auto [c, u, v] : adj) {
		if (!uf_union(u, v))
			continue;

		cost += c;
		cnt++;

		if (cnt == N) // 입구까지 포함
			break;
	}

	return cost * cost;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> M;

	for (int u, v, c, i = 0; i <= M; i++) { // 입구 입력까지 포함해서 등호
		cin >> u >> v >> c;
		c = (c == 0 ? 1 : 0); // 오르막이 0이고 내리막이 1로 들어옴
		adj.push_back({ c, u, v });
	}

	sort(adj.begin(), adj.end(), greater<>());
	int worst_cost = solve();
	fill(p.begin(), p.end(), -1);
	sort(adj.begin(), adj.end());
	int best_cost = solve();

	cout << worst_cost - best_cost;
}