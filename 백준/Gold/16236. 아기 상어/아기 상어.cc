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
int N, total_time = 0;
int cur_x, cur_y, cur_size = 2, cur_eat = 0;
int board[25][25], is_eated[25][25];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
vector<tuple<int, int, int>> fish; // (x, y, size)
//=========================//

int bfs(int en_x, int en_y) {
	int vis[25][25] = { 0, };
	queue<pair<int, int>> q;

	vis[cur_x][cur_y] = 1;
	q.push({ cur_x, cur_y });
	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N)
				continue;
			if (board[nx][ny] != 9 && cur_size < board[nx][ny])
				continue;
			if (vis[nx][ny])
				continue;

			vis[nx][ny] = vis[x][y] + 1;
			q.push({ nx, ny });
		}
	}

	return vis[en_x][en_y] - 1;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 9)
				tie(cur_x, cur_y) = { i, j };
			else if (board[i][j] != 0)
				fish.push_back({ i, j, board[i][j] });
		}
	}

	while (cur_eat < fish.size()) {
		int mn_time = INT_MAX;
		pair<int, int> eated_fist;
		for (auto [x, y, fish_size] : fish) {
			if (is_eated[x][y])
				continue;
			if (cur_size > fish_size) {
				int tmp_dist = bfs(x, y); // bfs로 도달 못하면 -1 반환
				if (tmp_dist != -1 && mn_time > tmp_dist) {
					mn_time = tmp_dist;
					eated_fist = { x, y };
				}
			}
		}

		if (mn_time == INT_MAX)
			break;

		total_time += mn_time;
		is_eated[eated_fist.X][eated_fist.Y] = 1;
		tie(cur_x, cur_y) = eated_fist;
		cur_eat++;
		if (cur_eat == cur_size) {
			cur_size++;
			cur_eat = 0;
		}
	}

	cout << total_time;
}