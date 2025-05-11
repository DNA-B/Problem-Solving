#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_set>
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
int N, K, mx = -1;
int vis[100005], tree[100005];
vector<int> adj[100005];
//=========================//

void solve(int cur, int dist) {
	if (dist >= K)
		return;

	for (auto nxt : adj[cur]) {
		if (!vis[nxt]) {
			vis[nxt] = true;
			mx += tree[nxt];
			solve(nxt, dist + 1);
		}
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> K;

	int u, v;
	for (int i = 0; i < N - 1; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 0; i < N; i++)
		cin >> tree[i];

	vis[0] = true;
	mx = tree[0];
	solve(0, 0);
	cout << mx;
}