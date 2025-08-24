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
int N, P;
int C[10005];
vector<int> p(10005, -1);
vector<tuple<int, int, int>> edges;
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

	cin >> N >> P;

	int c;
	for (int i = 1; i <= N; i++)
		cin >> C[i];

	int u, v, l;
	for (int i = 0; i < P; i++) {
		cin >> u >> v >> l;
		int cost = (2 * l) + (C[u] + C[v]);
		edges.push_back({ cost, u, v });
	}

	sort(edges.begin(), edges.end());

	int cnt = 0, total = 0;
	for (auto [cost, u, v] : edges) {
		if (!uf_union(u, v))
			continue;

		total += cost;
		cnt++;

		if (cnt == N - 1)
			break;
	}

	cout << *min_element(C + 1, C + (N + 1)) + total;
}