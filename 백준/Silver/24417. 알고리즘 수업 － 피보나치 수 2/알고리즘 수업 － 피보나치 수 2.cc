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
const ll MOD = 1000000007;
ll N;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	ll a = 1, b = 1, c;
	for (int i = 2; i < N; i++) {
		c = ((a % MOD) + (b % MOD)) % MOD;
		a = b % MOD;
		b = c % MOD;
	}

	cout << c << ' ' << N - 2;
}