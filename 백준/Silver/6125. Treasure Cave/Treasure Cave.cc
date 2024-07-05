#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define BOUND 5001
#define INF 0x3f3f3f3f
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int P, NS, T;
int res = -1;
int path[BOUND];
vector<int> adj[BOUND];
/***********************/

void dfs(int cur, int cnt) {
	if (cur == T) {
		res = cnt;
		return;
	}

	for (auto nxt : adj[cur]) {
		if (!path[nxt]) {
			path[nxt] = cur;
			dfs(nxt, cnt + 1);
		}
	}
}

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> P >> NS >> T;

	for (int x, y, z, i = 0; i < NS; i++) {
		cin >> x >> y >> z;
		adj[x].push_back(y);
		adj[x].push_back(z);
	}

	dfs(1, 1);

	int cur_path = T;
	stack<int> st;
	while (1) {
		if (cur_path == 0)
			break;

		st.push(cur_path);
		cur_path = path[cur_path];
	}

	cout << res << "\n";

	while (!st.empty()) {
		cout << st.top() << "\n";
		st.pop();
	}

	return 0;
}