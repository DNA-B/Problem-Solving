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
int T;
bool flag = 0;
char board[15][15];
vector<pair<int, int>> v;
//=========================//

bool check(pair<int, int> xy) {
	auto [x, y] = xy;
	int loc_x, loc_y, bound_x1, bound_x2, bound_y1, bound_y2;

	loc_x = x / 3;
	loc_y = y / 3;
	bound_x1 = 3 * loc_x; // 정사각형 세로 시작점
	bound_x2 = 3 * (loc_x + 1); // 정사각형 세로 끝점
	bound_y1 = 3 * loc_y; // 정사각형 가로 시작점
	bound_y2 = 3 * (loc_y + 1); // 정사각형 가로 끝점

	for (int i = 0; i < 9; i++) {
		if (board[x][i] == board[x][y] && i != y) // 가로에 같은 숫자
			return false;
	}

	for (int i = bound_x1; i < bound_x2; i++) {
		for (int j = bound_y1; j < bound_y2; j++) {
			if (board[i][j] == board[x][y] && (i != x && j != y)) // 정사각형에 같은 숫자
				return false;
		}
	}

	for (int i = 0; i < 9; i++) {
		if (board[i][y] == board[x][y] && i != x) // 세로에 같은 숫자
			return false;
	}

	return true;
}

void solve(int cur) {
	if (flag)
		return;
	if (cur == v.size()) {
		for (int i = 0; i < 9; i++)
			cout << board[i] << '\n';
		flag = 1;
		return;
	}

	auto [nx, ny] = v[cur];
	for (int i = 1; i <= 9; i++) {
		board[nx][ny] = i + '0';
		if (check({ nx, ny }))
			solve(cur + 1);
	}

	board[nx][ny] = 0 + '0'; // 해가 없으면 다시 0으로
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		v.clear();
		flag = 0;

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cin >> board[i][j];
				if (board[i][j] == '0')
					v.push_back({ i, j });
			}
		}

		cout << "Scenario #" << tc << ":\n";
		solve(0);
		cout << '\n';
	}
}