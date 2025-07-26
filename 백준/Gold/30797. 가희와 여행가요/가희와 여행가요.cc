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
int N, Q, mx = -1;
vector<int> p(200005, -1);
vector<tuple<int, int, int, int>> adj;
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

	cin >> N >> Q;

	int f, t, c, tm;
	while (Q--) {
		cin >> f >> t >> c >> tm;
		adj.push_back({ c, tm, f, t });
	}

	sort(adj.begin(), adj.end());

	ll cost = 0;
	int cnt = 0;
	for (auto& [c, tm, f, t] : adj) {
		if (uf_union(f, t)) {
			cost += c;
			cnt++;
			mx = max(mx, tm);
		}

		if (cnt == N - 1) {
			cout << mx << ' ' << cost;
			exit(0);
		}
	}

	cout << -1;
}