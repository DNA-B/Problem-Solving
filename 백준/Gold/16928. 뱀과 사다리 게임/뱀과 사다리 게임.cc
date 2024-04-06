#define _CRT_SECURE_NO_WARNINGS
#define GOAL 100
#include <bits/stdc++.h>

using namespace std;

int N, M;
map<int, int> snake_ladder;
vector<int> vis(101, -1);
queue<int> q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M;

	for (int u, v, i = 0; i < N + M; i++) {
		cin >> u >> v;
		snake_ladder[u] = v;
	}

	vis[1] = 0;
	q.push(1);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur == GOAL) {
			cout << vis[GOAL];
			break;
		}

		for (int i = 1; i <= 6; i++) {
			int nx = cur + i;
			auto teleport_idx = snake_ladder.find(nx);

			if (nx < 1 || nx > 100)
				continue;
			if (vis[nx] != -1)
				continue;

			if (teleport_idx != snake_ladder.end()) { // 해당 좌표에 사다리나 뱀이 있음
				if (vis[teleport_idx->second] != -1) // 이동한 곳을 이미 방문했다면 skip
					continue;

				vis[nx] = vis[teleport_idx->second] = vis[cur] + 1;
				q.push(teleport_idx->second);
			}
			else { // 해당 좌표에 아무것도 없음
				vis[nx] = vis[cur] + 1;
				q.push(nx);
			}
		}
	}

	return 0;
}