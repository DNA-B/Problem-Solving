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
int T, N, M;
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

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		fill(p.begin(), p.end(), -1);
		adj.clear();

		cin >> N >> M;

		int u, v, c;
		while (M--) {
			cin >> u >> v >> c;
			adj.push_back({ c, u, v });
		}

		sort(adj.begin(), adj.end(), greater<>());

		int mn = INT_MAX, cnt = 0;
		for (auto& [cost, u, v] : adj) {
			if (!uf_union(u, v))
				continue;

			cnt++;
			mn = min(mn, cost);

			if (uf_find(1) == uf_find(N)) {
				cout << "Scenario #" << tc << ":\n" << mn << "\n\n";
				break;
			}

			if (cnt == N - 1)
				break;
		}
	}
}