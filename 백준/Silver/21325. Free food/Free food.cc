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
int N, M, root;
vector<int> adj[100005];
int vis[100005], chk[100005];
//=========================//

int dfs(int cur) {
	if (chk[cur])
		return 1;

	int res = 0;
	for (int nxt : adj[cur])
		res += dfs(nxt);

	return res;
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
		if (x == 0) root = i;
		else adj[x].push_back(i);
	}

	for (int i = 1; i <= M; i++) {
		cin >> x;
		chk[x] = 1;
	}

	cout << dfs(root);
}