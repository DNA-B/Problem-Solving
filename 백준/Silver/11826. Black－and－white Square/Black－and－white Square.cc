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
int N, M, cnt = 0;
int board[55][55], vis[55][55];
vector<int> v;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> M;

	bool is_full_filled = true;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (!board[i][j]) is_full_filled = false;
		}
	}

	if (is_full_filled) {
		if (N <= M) {
			cout << N << '\n';
			for (int i = 1; i <= N; i++) cout << -i << ' ';
		}
		else {
			cout << M << '\n';
			for (int i = 1; i <= M; i++) cout << i << ' ';
		}
		exit(0);
	}

	for (int col = 0; col < M; col++) { // 세로
		bool flag = true;
		for (int row = 0; row < N; row++) {
			if (!board[row][col]) {
				flag = false;
				break;
			}
		}

		if (flag) {
			for (int row = 0; row < N; row++) vis[row][col] = 1;
			v.push_back(col + 1);
		}
	}

	for (int row = 0; row < N; row++) { // 가로
		bool flag = true;
		for (int col = 0; col < M; col++) {
			if (!board[row][col]) {
				flag = false;
				break;
			}
		}

		if (flag) {
			for (int col = 0; col < M; col++) vis[row][col]++;
			v.push_back(-(row + 1));
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] && !vis[i][j]) { // 보드는 칠해져있는데 색칠을 안 한 경우
				cout << -1;
				exit(0);
			}
		}
	}

	cout << v.size() << '\n';
	for (int x : v) cout << x << ' ';
}