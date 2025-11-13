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
int board[5][5];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
unordered_map<string, bool> um;
//=========================//

void solve(int x, int y, string cur) {
	stack<tuple<int, int, string>> st;

	st.push({ x, y, cur });
	while (!st.empty()) {
		auto [x, y, num] = st.top();
		st.pop();

		if (num.length() == 6) {
			um[num] = true;
			continue;
		}

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5)
				continue;

			st.push({ nx, ny, num + to_string(board[nx][ny]) });
		}
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
			cin >> board[i][j];
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
			solve(i, j, to_string(board[i][j]));
	}

	cout << um.size();
}