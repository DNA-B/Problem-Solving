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
int T, R, C;
char arr[10][10];
/***********************/

bool check() {
	for (int i = 0; i <= R - 2; i++) {
		for (int j = 0; j <= C - 2; j++) {
			if (arr[i][j] == '#') { // 현재 위치가 파란 그림이고
				if (arr[i + 1][j] == '#' && arr[i + 1][j + 1] == '#' && arr[i][j + 1] == '#') { // 현재 위치 기준 오른쪽 아래 대각선으로 4칸이 파란 그림이면
					arr[i][j] = arr[i + 1][j + 1] = '/'; // 빨간 그림으로 교체
					arr[i + 1][j] = arr[i][j + 1] = '\\';
				}
			}
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (arr[i][j] == '#') // 파란 그림이 하나라도 남아있으면 false
				return false;
		}
	}

	return true;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> R >> C;

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++)
				cin >> arr[i][j];
		}

		cout << "Case #" << tc << ":\n";

		if (check()) {
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++)
					cout << arr[i][j];
				cout << '\n';
			}
		}
		else {
			cout << "Impossible\n";
		}
	}

	return 0;
}