#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define INF 0x3f3f3f3f
#define LLINF 1e18
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N;
int board[31][31];
ll mem[31][31];
/***********************/

ll to_binary(string tmp) {
	return bitset<60>(tmp).to_ullong();
}

void solve(string cur, int x, int y) {
	if (cur.size() > 2 * N - 1)
		return;
	if (x > N || y > N)
		return;

	mem[x][y] = max(mem[x][y], to_binary(cur));
	solve(cur + to_string(board[x + 1][y]), x + 1, y);
	solve(cur + to_string(board[x][y + 1]), x, y + 1);
}

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> board[i][j];
	}

	solve(to_string(board[0][0]), 0, 0);
	cout << mem[N - 1][N - 1];

	return 0;
}