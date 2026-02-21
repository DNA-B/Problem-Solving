#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

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
int K, N, M, S;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> K;

	for (int tc = 1; tc <= K; tc++) {
		set<int> adj[105];

		cin >> N >> M;

		int u, v;
		for (int i = 0; i < M; i++) {
			cin >> u >> v;
			adj[u].insert(v);
			adj[v].insert(u);
		}

		cin >> S;

		cout << "Data Set " << tc << ":\n";
		for (int x : adj[S])
			cout << x << ' ';
		cout << "\n\n";
	}
}