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
int T, R, C;
vector<int> p(250005, -1);
vector<tuple<int, int, int>> adj;
//=========================//

int uf_find(int x) {
	if (p[x] < 0) return x;
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

	while (T--) {
		cin >> R >> C;

		for (int x, i = 0; i < R; i++) {
			for (int j = 0; j < C - 1; j++) {
				cin >> x;
				adj.push_back({ x, i * C + j, i * C + (j + 1) });
			}
		}

		for (int x, i = 0; i < R - 1; i++) {
			for (int j = 0; j < C; j++) {
				cin >> x;
				adj.push_back({ x, i * C + j, (i + 1) * C + j });
			}
		}

		sort(adj.begin(), adj.end());

		int cnt = 0, cost = 0;
		for (auto [w, u, v] : adj) {
			if (!uf_union(u, v))
				continue;

			cnt++;
			cost += w;

			if (cnt == R * C - 1)
				break;
		}

		cout << cost << '\n';

		fill(p.begin(), p.end(), -1);
		adj.clear();
	}
}