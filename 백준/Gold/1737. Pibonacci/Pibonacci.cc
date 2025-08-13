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
const ll MOD = 1e18;
int N;
ll mem[1005][1005];
//=========================//

ll solve(int i, int j) {
	if (mem[i][j] != -1)
		return mem[i][j];
	if (i - PI * j >= 0 && i - PI * j <= PI)
		return 1;

	return mem[i][j] = (solve(i - 1, j) + solve(i, j + 1)) % MOD;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;
	memset(mem, -1, sizeof(mem));
	cout << solve(N, 0);
}