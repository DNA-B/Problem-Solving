#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
//========= MACRO =========//
#define PI 3.1415926535897932
#define INT_INF 0x3f3f3f3f
#define LL_INF 1e18
#define ll long long
#define X first
#define Y second
//=========================//

//======= VARIABLEs =======//
int N, M, res = 0;
bool adj[105][105];
//=========================//

void solve() {
	for (int k = 1; k <= N; k++) {
		for (int st = 1; st <= N; st++) {
			for (int en = 1; en <= N; en++) {
				if (adj[st][k] && adj[k][en])
					adj[st][en] = true;
			}
		}
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> M;

	for (int u, v, i = 0; i < M; i++) {
		cin >> u >> v;
		adj[u][v] = true;
	}

	solve();

	for (int i = 1; i <= N; i++) {
		int in = 0, out = 0;
		for (int j = 1; j <= N; j++) {
			in += adj[i][j];
			out += adj[j][i];
		}

		if (in > (N - 1) / 2 || out > (N - 1) / 2)
			res++;
	}

	cout << res;
	return 0;
}