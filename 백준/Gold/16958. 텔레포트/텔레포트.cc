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
int N, M, T, u, v;
int dist[1005][1005];
bool is_special[1005];
pair<int, int> cities[1005];
//=========================//

int find_mn(int x) {
	int mn = INF, mn_idx = INF;

	for (int i = 1; i <= N; i++) {
		if (!is_special[i])
			continue;

		if (mn > dist[x][i]) {
			mn = dist[x][i];
			mn_idx = i;
		}
	}

	return mn_idx;
}

int solve(int st, int en) {
	int direct = dist[st][en];

	// 둘 다 특별한 도시
	if (is_special[st] && is_special[en])
		direct = min(direct, T);

	// 한번에 가는 것과 거쳤다 오는 것 비교
	int near_st = find_mn(st);
	int near_en = find_mn(en);
	direct = min(direct, dist[st][near_st] + T + dist[near_en][en]);

	return direct;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> T;
	for (int i = 1; i <= N; i++)
		fill(dist[i], dist[i] + (N + 1), INF);

	for (int i = 1; i <= N; i++)
		cin >> is_special[i] >> cities[i].X >> cities[i].Y;

	for (int i = 1; i <= N; i++) {
		dist[i][i] = 0;
		for (int j = i + 1; j <= N; j++)
			dist[i][j] = dist[j][i] = abs(cities[i].X - cities[j].X) + abs(cities[i].Y - cities[j].Y);
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		cout << solve(u, v) << '\n';
	}

	return 0;
}