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
int N, M, T;
int dist[1005][1005];
bool is_special[1005];
pair<int, int> cities[1005];
//=========================//

void solve() {
	for (int k = 1; k <= N; k++) {
		for (int st = 1; st <= N; st++) {
			for (int en = 1; en <= N; en++) {
				if (dist[st][en] > dist[st][k] + dist[k][en])
					dist[st][en] = dist[st][k] + dist[k][en];
			}
		}
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> T;
	for (int i = 1; i <= N; i++)
		fill(dist[i], dist[i] + (N + 1), INF);

	for (int i = 1; i <= N; i++)
		cin >> is_special[i] >> cities[i].X >> cities[i].Y;

	for (int i = 1; i < N; i++) {
		dist[i][i] = 0;
		for (int j = i + 1; j <= N; j++) {
			dist[i][j] = dist[j][i] = abs(cities[i].X - cities[j].X) + abs(cities[i].Y - cities[j].Y);
			if (is_special[i] && is_special[j]) // 둘 다 특별한 도시
				dist[i][j] = dist[j][i] = min(dist[i][j], T); // dist[i][j]랑 dist[j][i]랑 값이 똑같아서 아무거나 min에 들어가도 됨.
		}
	}

	solve(); // 플로이드
	
    cin >> M;
	for (int u, v, i = 0; i < M; i++) {
		cin >> u >> v;
		cout << dist[u][v] << '\n';
	}

	return 0;
}