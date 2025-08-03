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
int N, M, root, res = 0, mn = INT_MAX;
vector<int> adj[100005];
int vis[100005], chk[100005];
unordered_map<int, int> emp;
//=========================//

void dfs(int cur) {
	for (int nxt : adj[cur]) {
		if (!vis[nxt]) {
			vis[nxt] = vis[cur] + chk[cur];
			mn = min(mn, vis[nxt]);
			dfs(nxt);
		}
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> M;

	int x;
	for (int i = 1; i <= N; i++) {
		cin >> x;
		if (x == 0) {
			root = i;
			continue;
		}
		adj[x].push_back(i);
	}

	for (int i = 1; i <= M; i++) {
		cin >> x;
		chk[x] = 1;
	}

	if (chk[root]) { // CEO가 참석하면 무조건 그 사람이 낸다.
		cout << 1;
		exit(0);
	}

	vis[root] = 1;
	dfs(root);

	for (int i = 1; i <= N; i++) {
		if (vis[i] == mn && chk[i])
			res++;
	}

	cout << res;
}