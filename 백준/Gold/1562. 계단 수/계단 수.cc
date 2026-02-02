#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

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
const int MOD = 1000000000;
int N;
int mem[101][10][1 << 10]; // { 자릿수, 현재 숫자, 숫자 집합 }
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	for (int j = 1; j <= 9; j++)
		mem[1][j][1 << j] = 1;

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int mask = 0; mask < (1 << 10); mask++) {
				int nxt_mask = mask | (1 << j);

				if (j > 0 && mem[i - 1][j - 1][mask]) {
					mem[i][j][nxt_mask] += mem[i - 1][j - 1][mask];
					mem[i][j][nxt_mask] %= MOD;
				}

				if (j < 9 && mem[i - 1][j + 1][mask]) {
					mem[i][j][nxt_mask] += mem[i - 1][j + 1][mask];
					mem[i][j][nxt_mask] %= MOD;
				}
			}
		}
	}

	int total = (1 << 10) - 1;
	ll res = 0;
	for (int i = 0; i <= 9; i++) {
		res += mem[N][i][total] % MOD;
		res %= MOD;
	}

	cout << res;
}