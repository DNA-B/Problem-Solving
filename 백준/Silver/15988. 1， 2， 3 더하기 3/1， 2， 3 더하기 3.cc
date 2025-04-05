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
const int MOD = 1'000'000'009;
int T, N;
ll mem[1000005];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	mem[1] = 1;
	mem[2] = 2;
	mem[3] = 4;

	for (int i = 4; i <= 1000000; i++)
		mem[i] = (mem[i - 1] + mem[i - 2] + mem[i - 3]) % MOD;

	cin >> T;

	while (T--) {
		cin >> N;
		cout << mem[N] << "\n";
	}
}