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
int N, M;
int deg[1005], mem[1005];
vector<int> adj[1005];
queue<int> q;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> M;

	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		deg[b]++;
	}

	for (int i = 1; i <= N; i++) {
		if (!deg[i]) {
			mem[i] = 1;
			q.push(i);
		}
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int nxt : adj[cur]) {
			deg[nxt]--;
			mem[nxt] = max(mem[nxt], mem[cur] + 1);

			if (!deg[nxt])
				q.push(nxt);
		}
	}

	for (int i = 1; i <= N; i++)
		cout << mem[i] << ' ';
}