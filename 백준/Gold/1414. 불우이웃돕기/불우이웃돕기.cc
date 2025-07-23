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
int N, total = 0;
vector<int> p(55, -1);
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

	cin >> N;

	char ch;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> ch;
			if (ch == '0') continue;
			int w = (islower(ch) ? (ch - 'a') + 1 : (ch - 'A') + 27);
			total += w;
			if (i == j) continue;
			adj.push_back({ w, i, j });
		}
	}

	sort(adj.begin(), adj.end());

	int cnt = 0, cost = 0;
	for (auto [w, u, v] : adj) {
		if (!uf_union(u, v))
			continue;

		cost += w;
		cnt++;

		if (cnt == N - 1)
			break;
	}

	cout << (cnt != N - 1 ? -1 : total - cost);
}