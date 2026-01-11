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
int N, K, en;
int vis[15];
vector<ll> line_to_stations[15];
queue <ll> q;
unordered_map<ll, vector<int>> station_to_lines;
//=========================//

void bfs() {
	while (!q.empty()) {
		int cur = q.front(); // 현재 호선
		q.pop();

		for (int nxt : line_to_stations[cur]) { // 현재 호선에서 탈 수 있는 역들
			if (nxt == en) {
				cout << vis[cur];
				exit(0);
			}

			for (int line : station_to_lines[nxt]) { // nxt 역에서 탈 수 있는 라인
				if (vis[line] != -1)
					continue;

				vis[line] = vis[cur] + 1;
				q.push(line);
			}
		}
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;
	memset(vis, -1, sizeof(vis));

	for (int i = 0; i < N; i++) {
		cin >> K;

		int x;
		while (K--) {
			cin >> x;
			station_to_lines[x].push_back(i);
			line_to_stations[i].push_back(x);
			if (x == 0) { // 서울역에서 탈 수 있는 호선
				q.push(i);
				vis[i] = 0;
			}
		}
	}

	cin >> en;
	bfs();
	cout << -1;
}