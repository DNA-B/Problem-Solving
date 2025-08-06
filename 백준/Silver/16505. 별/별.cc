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
int N;
char board[1050][1050];
//=========================//

void solve(int x, int y, int depth) {
	board[x][y] = '*';

	if (depth > N)
		return;

	solve(x, y, depth + 1);
	solve(x + pow(2, N - depth), y, depth + 1);
	solve(x, y + pow(2, N - depth), depth + 1);
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	memset(board, ' ', sizeof(board));
	solve(1, 1, 1);

	for (int i = 1; i <= pow(2, N); i++) {
		for (int j = 1; j <= pow(2, N) - i + 1; j++)
			cout << board[i][j];
		cout << '\n';
	}
}