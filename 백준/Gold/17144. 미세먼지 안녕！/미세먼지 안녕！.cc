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
int R, C, T, cur_time = 0;
int board[55][55];
pair<int, int> U, D;
//=========================//

int dust_diffusion(int x, int y, int d) {
	int dx[] = { 1, -1, 0, 0 };
	int dy[] = { 0, 0, 1, -1 };
	int cnt = 0;

	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (nx < 0 || nx >= R || ny < 0 || ny >= C)
			continue;
		if (board[nx][ny] == -1)
			continue;

		board[nx][ny] += d / 5;
		cnt++;
	}

	return cnt;
}

void air_purifier(bool mode) {
	pair<int, int> cycle_U[] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
	pair<int, int> cycle_D[] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

	int dir = 0;
	auto [x, y] = (mode ? D : U);
	auto [cx, cy] = (mode ? cycle_D[dir] : cycle_U[dir]);

	int cur_x = x + cx;
	int cur_y = y + cy;
	while (cur_x != x || cur_y != y) {
		if (board[cur_x - cx][cur_y - cy] == -1)
			board[cur_x][cur_y] = 0;
		else // 문제에서 제시한 방향이랑 반대로 가면서 내 이전칸으로 먼지 옮기기
			swap(board[cur_x][cur_y], board[cur_x - cx][cur_y - cy]);

		if (cur_x + cx < 0 || cur_x + cx >= R || cur_y + cy < 0 || cur_y + cy >= C ||
			(mode == 0 && cur_x + cx > U.X) ||
			(mode == 1 && cur_x + cx < D.X)) {
			dir = (dir + 1) % 4;
			tie(cx, cy) = (mode ? cycle_D[dir] : cycle_U[dir]);
		}

		cur_x += cx;
		cur_y += cy;
	}
}

void step() {
	// 미세먼지 확산
	vector<tuple<int, int, int>> dust;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (board[i][j] > 0)
				dust.push_back({ i, j, board[i][j] });
		}
	}

	for (auto [x, y, d] : dust) {
		if (board[x][y] / 5 > 0) {
			int cnt = dust_diffusion(x, y, d);
			board[x][y] -= (d / 5) * cnt;
		}
	}

	// 공기청정기 작동, 0: 위, 1: 아래
	air_purifier(0);
	air_purifier(1);
}


int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> R >> C >> T;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> board[i][j];

			if (board[i][j] == -1) {
				if (!U.X && !U.Y)
					U = { i, j };
				else
					D = { i, j };
			}
		}
	}

	while (cur_time < T) {
		step();
		cur_time++;
	}

	int total = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (board[i][j] > 0)
				total += board[i][j];
		}
	}

	cout << total;
}