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
int N, P, R, C;
int arr[1005][1005], chk[1005][1005];
ll mem1[1005][1005], mem2[1005][1005];
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

	for (int i = R; i <= N; i++) {
		for (int j = C; j <= N; j++)
			mem1[i][j] = max(mem1[i - 1][j], mem1[i][j - 1]) + arr[i][j];
	}

	cin >> P;
	while (P--) {
		cin >> R >> C;
		mem2[R][C] = mem1[R][C];
		chk[R][C] = 1;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (chk[i - 1][j]) {
				mem2[i][j] = max(mem2[i][j], mem2[i - 1][j] + arr[i][j]);
				chk[i][j] = 1;
			}
			if (chk[i][j - 1]) {
				mem2[i][j] = max(mem2[i][j], mem2[i][j - 1] + arr[i][j]);
				chk[i][j] = 1;
			}
		}
	}

	cout << mem2[N][N];
}