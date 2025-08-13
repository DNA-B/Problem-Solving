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
int I, N, K, total_ink = 0, jump_cnt = 0;
string INK, orders;
char board[105][105];
pair<int, int> square;
vector<pair<int, int>> obstacles;
//=========================//

void move(char dir) {
	auto& [x, y] = square;
	int tmp_x = x, tmp_y = y;

	switch (dir) {
		case 'U':
			if (x - 1 >= 0 && board[x - 1][y] == '.')
				x -= 1;
			break;
		case 'D':
			if (x + 1 < N && board[x + 1][y] == '.')
				x += 1;
			break;
		case 'L':
			if (y - 1 >= 0 && board[x][y - 1] == '.')
				y -= 1;
			break;
		case 'R':
			if (y + 1 < N && board[x][y + 1] == '.')
				y += 1;
			break;
	}

	if (x != tmp_x || y != tmp_y) {
		board[tmp_x][tmp_y] = '.';
		board[x][y] = '@';
	}
}

void jump() {
	auto& [x, y] = square;

	for (auto& [obs_x, obs_y] : obstacles) {
		if (abs(x - obs_x) + abs(y - obs_y) <= total_ink)
			board[obs_x][obs_y] = INK[jump_cnt % I];
	}

	jump_cnt++;
	total_ink = 0;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> I >> N >> K >> INK;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] == '@')
				square = { i, j };
			else if (board[i][j] == '#')
				obstacles.push_back({ i, j });
		}
	}

	cin >> orders;

	for (char& ch : orders) {
		if (ch == 'U' || ch == 'D' || ch == 'L' || ch == 'R')
			move(ch);
		else if (ch == 'j')
			total_ink++;
		else if (ch == 'J')
			jump();
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << board[i][j];
		cout << '\n';
	}
}