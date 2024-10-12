#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define PI 3.1415926535897932
#define MOD 1000000007
#define INT_INF 0x3f3f3f3f
#define LL_INF 1e18
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N, M, res = 0;
int path[10005];
int adj[105][105];
/***********************/

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> M;

	for (int i = 0; i < M; i++)
		cin >> path[i];

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> adj[i][j];
		}
	}

	for (int k = 1; k <= N; k++) {
		for (int st = 1; st <= N; st++) {
			for (int en = 1; en <= N; en++) {
				if (adj[st][en] > adj[st][k] + adj[k][en])
					adj[st][en] = adj[st][k] + adj[k][en];
			}
		}
	}

	for (int i = 1; i < M; i++)
		res += adj[path[i - 1]][path[i]];

	cout << res;
	return 0;
}