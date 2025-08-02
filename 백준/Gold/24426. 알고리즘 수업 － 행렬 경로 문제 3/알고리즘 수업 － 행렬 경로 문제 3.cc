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
int N, R, C;
int arr[1005][1005];
ll mem[1005][1005][2];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			cin >> arr[i][j];
	}

	cin >> R >> C;

    // 거치고
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (i == 1)
				mem[i][j][0] = mem[i][j - 1][0] + arr[i][j];
			else if (j == 1)
				mem[i][j][0] = mem[i - 1][j][0] + arr[i][j];
			else
				mem[i][j][0] = max(mem[i - 1][j][0], mem[i][j - 1][0]) + arr[i][j];
		}
	}

	for (int i = R; i <= N; i++) {
		for (int j = C; j <= N; j++) {
			if (i == 1)
				mem[i][j][0] = mem[i][j - 1][0] + arr[i][j];
			else if (j == 1)
				mem[i][j][0] = mem[i - 1][j][0] + arr[i][j];
			else
				mem[i][j][0] = max(mem[i - 1][j][0], mem[i][j - 1][0]) + arr[i][j];
		}
	}

    // 거치지 않고
	mem[R][C][1] = -LL_INF;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == R && j == C)
				continue;

			if (i == 1)
				mem[i][j][1] = mem[i][j - 1][1] + arr[i][j];
			else if (j == 1)
				mem[i][j][1] = mem[i - 1][j][1] + arr[i][j];
			else
				mem[i][j][1] = max(mem[i - 1][j][1], mem[i][j - 1][1]) + arr[i][j];
		}

	}

	cout << mem[N][N][0] << ' ' << mem[N][N][1];
}