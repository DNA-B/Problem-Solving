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
int board[1025][1025];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> board[i][j];
	}

	while (N > 1) {
		int x = 0, y = 0;

		for (int i = 0; i < N; i += 2) {
			for (int j = 0; j < N; j += 2) {
				int arr[] = { board[i][j], board[i + 1][j], board[i][j + 1], board[i + 1][j + 1] };
				sort(arr, arr + 4);
				board[x][y++] = arr[2];
				if (y == N / 2) {
					x++;
					y = 0;
				}
			}
		}

		N /= 2;
	}

	cout << board[0][0];
}