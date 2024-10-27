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
int H, N, M, res = 0;
string arr[1005];
int dx[] = { 0, 0, 1, 1, -1, -1 };
int dy[] = { 2, -2, 1, -1, 1, -1 };
priority_queue<int> pq;
//=========================//

int bfs(int x, int y) {
	int cnt = 1;
	queue<pair<int, int>> q;

	q.push({ x, y });
	arr[x][y] = '#';

	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();

		for (int dir = 0; dir < 6; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= arr[nx].size())
				continue;
			if (arr[nx][ny] != '.')
				continue;

			cnt++;
			arr[nx][ny] = '#';
			q.push({ nx, ny });
		}
	}
	return cnt;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> H >> N >> M;
	cin.ignore();

	for (int i = 0; i < N; i++)
		getline(cin, arr[i]);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			if (arr[i][j] == '.')
				pq.push(bfs(i, j));
		}
	}

	while (!pq.empty() && H) {
		int cur = pq.top(); pq.pop();
		res++;
		if (cur >= H) break;
		H -= cur;
	}

	cout << res;
	return 0;
}