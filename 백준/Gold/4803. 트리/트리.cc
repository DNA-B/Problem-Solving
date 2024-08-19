#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

/******** MACRO ********/
#define INT_INF 0x3f3f3f3f
#define LL_INF 1e18
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int T = 1, N, M;
int is_cycle[505];
vector<int> p(505, -1);
/***********************/

int uf_find(int x) {
	if (p[x] < 0)
		return x;
	return p[x] = uf_find(p[x]);
}

bool uf_union(int a, int b) {
	a = uf_find(a);
	b = uf_find(b);

	if (a == b) return false;
	if (p[a] == p[b]) p[a]--;

	if (p[a] < p[b]) p[b] = a;
	else p[a] = b;

	return true;
}

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	while (1) {
		int tree = 0;
		cin >> N >> M;

		fill(is_cycle + 1, is_cycle + (N + 1), 0);
		fill(p.begin() + 1, p.begin() + (N + 1), -1);

		if (N == 0 && M == 0)
			break;

		for (int u, v, i = 0; i < M; i++) {
			cin >> u >> v;
			if (!uf_union(u, v))
				is_cycle[uf_find(u)] = 1; // 부모가 사이클을 보유함을 기록
		}

		for (int i = 1; i <= N; i++) {
			if (p[i] < 0 && !is_cycle[i])
				tree++;
		}

		if (tree == 0)
			cout << "Case " << T++ << ": " << "No trees.\n";
		else if (tree == 1)
			cout << "Case " << T++ << ": " << "There is one tree.\n";
		else
			cout << "Case " << T++ << ": " << "A forest of " << tree << " trees.\n";
	}

	return 0;
}