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
vector<int> p(1005, -1);
vector<tuple<int, int, int>> adj; // { cost, a, b }
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

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int x, j = 1; j <= N; j++) {
			cin >> x;
			if (i == j) continue;
			adj.push_back({ x, i, j });
		}
	}

	sort(adj.begin(), adj.end());

	int cnt = 0;
	ll total = 0;
	for (auto [cost, a, b] : adj) {
		if (!uf_union(a, b))
			continue;

		cnt++;
		total += cost;

		if (cnt == N - 1)
			break;
	}

	cout << total;
}