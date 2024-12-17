#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
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
int N;
int adj[1005][1005], deg[1005], chk[1005];
//=========================//

void solve(int cur) {
	for (; chk[cur] < N; chk[cur]++) {
		int nxt = chk[cur];
		while (adj[cur][nxt]) {
			adj[cur][nxt]--;
			adj[nxt][cur]--;
			solve(nxt);
		}
	}
	cout << cur + 1 << ' ';
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> adj[i][j];
			deg[i] += adj[i][j];
			deg[j] += adj[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		deg[i] /= 2;
		if (deg[i] & 1) {
			cout << -1;
			exit(0);
		}
	}
	solve(0);
}