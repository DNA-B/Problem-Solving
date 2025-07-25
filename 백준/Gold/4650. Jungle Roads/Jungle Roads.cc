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
int N;
vector<int> p(30, -1);
vector<tuple<int, char, char>> adj;
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

	while (cin >> N) {
		if (N == 0)
			break;

		fill(p.begin(), p.end(), -1);
		adj.clear();

		for (int i = 0; i < N - 1; i++) {
			int cur_adj;
			char cur;

			cin >> cur >> cur_adj;

			int nxt_cost;
			char nxt;
			for (int j = 0; j < cur_adj; j++) {
				cin >> nxt >> nxt_cost;
				adj.push_back({ nxt_cost, cur - 'A', nxt - 'A' });
			}
		}

		sort(adj.begin(), adj.end());

		int cost = 0, cnt = 0;
		for (auto& [c, u, v] : adj) {
			if (!uf_union(u, v))
				continue;

			cost += c;
			cnt++;

			if (cnt == N - 1)
				break;
		}

		cout << cost << '\n';
	}
}