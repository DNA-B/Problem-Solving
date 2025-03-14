#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
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
int N, M;
char board[10][10];
int mem_mn[10][10], mem_mx[10][10];
//=========================//

int calc(char op, int a, int b) { // 연산자, 피연산자1, 피연산자2
	switch (op) {
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
	}
}

void solve(int x, int y) {
	bool is_digit = ('0' <= board[x][y] && board[x][y] <= '5');
	int mx = INT_MIN, mn = INT_MAX;

	if (x - 1 > 0) {
		if (is_digit) {
			mx = max(mx, calc(board[x - 1][y], mem_mx[x - 1][y], board[x][y] - '0'));
			mn = min(mn, calc(board[x - 1][y], mem_mn[x - 1][y], board[x][y] - '0'));
		}
		else {
			mx = max(mx, mem_mx[x - 1][y]);
			mn = min(mn, mem_mn[x - 1][y]);
		}
	}
	if (y - 1 > 0) {
		if (is_digit) {
			mx = max(mx, calc(board[x][y - 1], mem_mx[x][y - 1], board[x][y] - '0'));
			mn = min(mn, calc(board[x][y - 1], mem_mn[x][y - 1], board[x][y] - '0'));
		}
		else {
			mx = max(mx, mem_mx[x][y - 1]);
			mn = min(mn, mem_mn[x][y - 1]);
		}
	}
	mem_mx[x][y] = mx;
	mem_mn[x][y] = mn;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			cin >> board[i][j];
		fill(mem_mx[i] + 1, mem_mx[i] + (N + 1), INT_MIN);
		fill(mem_mn[i] + 1, mem_mn[i] + (N + 1), INT_MAX);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == 1 && j == 1)
				mem_mx[i][j] = mem_mn[i][j] = board[i][j] - '0';
			else
				solve(i, j);
		}
	}
    
	cout << mem_mx[N][N] << ' ' << mem_mn[N][N];
}