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
int N, cnt = 0;
ll mem[16][16];
//=========================//

int matrix_path_rec(int i, int j) {
	if (i == 0 || j == 0) {
		cnt++;
		return 0;
	}
	return mem[i][j] + max(matrix_path_rec(i - 1, j), matrix_path_rec(i, j - 1));
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			cin >> mem[i][j];
	}

	matrix_path_rec(N, N);
	cout << cnt << ' ' << N * N;
}