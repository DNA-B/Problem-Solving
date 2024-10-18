#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define PI 3.1415926535897932
#define MOD 1000000007
#define INT_INF 0x3f3f3f3f
#define LL_INF 1e18
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N, x = 0, y = 0;
string order;
char arr[15][15];
/***********************/

void draw(int x, int y, bool mode) {
	if (mode == 0) {
		if (arr[x][y] == '.')
			arr[x][y] = '|';
		else if (arr[x][y] == '-')
			arr[x][y] = '+';
	}
	else {
		if (arr[x][y] == '.')
			arr[x][y] = '-';
		else if (arr[x][y] == '|')
			arr[x][y] = '+';
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	for (int i = 0; i < 15; i++)
		fill(arr[i], arr[i] + 15, '.');

	cin >> N >> order;

	for (char ch : order) {
		switch (ch) {
			case 'D':
				if (x + 1 < N) {
					draw(x, y, 0);
					x += 1;
					draw(x, y, 0);
				}
				break;
			case 'U':
				if (x - 1 >= 0) {
					draw(x, y, 0);
					x -= 1;
					draw(x, y, 0);
				}
				break;
			case 'L':
				if (y - 1 >= 0) {
					draw(x, y, 1);
					y -= 1;
					draw(x, y, 1);
				}
				break;
			case 'R':
				if (y + 1 < N) {
					draw(x, y, 1);
					y += 1;
					draw(x, y, 1);
				}
				break;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << arr[i][j];
		cout << '\n';
	}

	return 0;
}