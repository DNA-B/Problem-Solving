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
const int MOD = 1000000009; // 1e9 
int T, N;
ll mem[100005][5]; // 마지막 숫자가 무엇인지
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> T;

	mem[1][1] = 1;
	mem[2][2] = 1;
	mem[3][1] = mem[3][2] = mem[3][3] = 1;

	for (int i = 4; i <= 100000; i++) {
		mem[i][1] = (mem[i - 1][2] + mem[i - 1][3]) % MOD;
		mem[i][2] = (mem[i - 2][1] + mem[i - 2][3]) % MOD;
		mem[i][3] = (mem[i - 3][1] + mem[i - 3][2]) % MOD;
	}

	while (T--) {
		cin >> N;
		cout << (mem[N][1] + mem[N][2] + mem[N][3]) % MOD << '\n';
	}
}