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
const int MOD = 1000000007;
int N, cnt = 0;
int arr[1005][1005];
ll mem[2005][1005];
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

	mem[0][0] = 1;
	mem[1][0] = 1;
	mem[1][1] = 1;

	for (int i = 2; i <= 2 * N; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i)
				mem[i][j] = 1;
			else
				mem[i][j] = ((mem[i - 1][j - 1] % MOD) + (mem[i - 1][j] % MOD)) % MOD;
		}
	}

	cout << mem[2 * N][N] << ' ' << N * N;
}