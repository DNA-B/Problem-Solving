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
int N, K;
int dx[] = { -1, 1, INT_INF };
int vis[100005];
queue<int> q;
stack<int> path;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	fill(vis, vis + 100005, -1);
	cin >> N >> K;

	vis[N] = -2;
	q.push(N);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		dx[2] = cur;

		if (cur == K)
			break;

		for (int dir = 0; dir < 3; dir++) {
			int nx = cur + dx[dir];

			if (nx < 0 || nx > 100000)
				continue;
			if (vis[nx] != -1)
				continue;

			vis[nx] = cur;
			q.push(nx);
		}
	}

	int idx = K;
	path.push(K);
	while (idx != N) {
		idx = vis[idx];
		path.push(idx);
	}

	cout << path.size() - 1 << '\n'; // (경로의 개수 - 1)이 시작점 제외한 총 시간

	while (!path.empty()) {
		cout << path.top() << ' ';
		path.pop();
	}

	return 0;
}