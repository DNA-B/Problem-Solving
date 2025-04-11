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
int N, M; // 섬, 다리
int st, en;
vector<int> bridge;
vector<int> p(10001, -1);
tuple<int, int, int> edge[100001];
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

	cin >> N >> M;

	for (int a, b, cost, i = 0; i < M; i++) {
		cin >> a >> b >> cost;
		edge[i] = { cost, a, b };
	}

	cin >> st >> en;
	sort(edge, edge + M, greater<>());

	for (int i = 0; i < M; i++) {
		auto [cost, a, b] = edge[i];

		if (!uf_union(a, b))
			continue;

		bridge.push_back(cost);

		if (uf_find(st) == uf_find(en)) {
			cout << *min_element(bridge.begin(), bridge.end());
			exit(0);
		}
	}
}