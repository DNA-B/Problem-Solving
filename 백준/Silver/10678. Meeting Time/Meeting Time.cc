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
int N, M, A, B, C, D;
set<int> res1, res2;
vector<pair<int, int>> adj1[20], adj2[20];
//=========================//

void dfs1(int cur, int total) {
	if (cur == N) {
		res1.insert(total);
		return;
	}

	for (auto [nxt, cost] : adj1[cur])
		dfs1(nxt, total + cost);
}

void dfs2(int cur, int total) {
	if (cur == N) {
		res2.insert(total);
		return;
	}

	for (auto [nxt, cost] : adj2[cur])
		dfs2(nxt, total + cost);
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C >> D;
		adj1[A].push_back({ B, C });
		adj2[A].push_back({ B, D });
	}

	dfs1(1, 0);
	dfs2(1, 0);

	for (auto x : res1) {
		if (find(res2.begin(), res2.end(), x) != res2.end()) {
			cout << x << '\n';
			exit(0);
		}
	}

	cout << "IMPOSSIBLE";
}