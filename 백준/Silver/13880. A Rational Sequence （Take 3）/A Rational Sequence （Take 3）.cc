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
ll P, K, N;
//=========================//

pair<ll, ll> solve(ll n) {
	if (n == 1)
		return { 1, 1 };

	auto [p, q] = solve(n / 2);
	if (n % 2 == 0)
		return { p, p + q };  // 왼쪽
	else
		return { p + q, q };  // 오른쪽
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> P;

	for (int i = 0; i < P; i++) {
		cin >> K >> N;
		auto [p, q] = solve(N);
		cout << K << " " << p << "/" << q << "\n";
	}
}