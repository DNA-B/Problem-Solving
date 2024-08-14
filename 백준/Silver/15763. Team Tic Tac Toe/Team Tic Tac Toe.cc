#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

/******** MACRO ********/
#define INT_INF 0x3f3f3f3f
#define LL_INF 1e18
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
char board[10][10];
set<string> one, two;
/***********************/

void make_team(int i, int j, int x, int y) {
	string tmp = "";
	tmp += board[i][j]; tmp += board[x][y];
	sort(tmp.begin(), tmp.end());
	two.insert(tmp);
}

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			cin >> board[i][j];
	}

	if (board[1][1] == board[0][0] && board[0][0] == board[2][2]) // 왼쪽 대각선
		one.insert(to_string(board[1][1]));
	else if (board[1][1] != board[0][0] && board[0][0] == board[2][2])
		make_team(1, 1, 0, 0);
	else if (board[1][1] == board[0][0] && board[0][0] != board[2][2])
		make_team(0, 0, 2, 2);
	else if (board[1][1] == board[2][2] && board[0][0] != board[2][2])
		make_team(0, 0, 2, 2);

	if (board[1][1] == board[0][2] && board[0][2] == board[2][0])// 오른쪽 대각선
		one.insert(to_string(board[1][1]));
	else if (board[1][1] != board[0][2] && board[0][2] == board[2][0])
		make_team(1, 1, 0, 2);
	else if (board[1][1] == board[0][2] && board[0][2] != board[2][0])
		make_team(0, 2, 2, 0);
	else if (board[1][1] == board[2][0] && board[0][2] != board[2][0])
		make_team(0, 2, 2, 0);

	for (int i = 0; i < 3; i++) { // 가로
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
			one.insert(to_string(board[i][0]));
		else if (board[i][0] != board[i][1] && board[i][1] == board[i][2])
			make_team(i, 0, i, 1);
		else if (board[i][0] == board[i][1] && board[i][1] != board[i][2])
			make_team(i, 1, i, 1);
		else if (board[i][0] == board[i][2] && board[i][1] != board[i][2])
			make_team(i, 1, i, 2);
	}

	for (int i = 0; i < 3; i++) { // 세로
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
			one.insert(to_string(board[0][i]));
		else if (board[0][i] != board[1][i] && board[1][i] == board[2][i])
			make_team(0, i, 1, i);
		else if (board[0][i] == board[1][i] && board[1][i] != board[2][i])
			make_team(1, i, 2, i);
		else if (board[0][i] == board[2][i] && board[1][i] != board[2][i])
			make_team(1, i, 2, i);
	}

	cout << one.size() << '\n' << two.size();
	return 0;
}