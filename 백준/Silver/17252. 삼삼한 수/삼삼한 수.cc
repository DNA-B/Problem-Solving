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
int N;
int p3[20];
//=========================//

void solve(ll cur, int idx) {
	if (cur == N) {
		cout << "YES";
		exit(0);
	}
	if (cur > N || idx > 19) // 3^20 > INT_MAX
		return;

	solve(cur + p3[idx], idx + 1);
	solve(cur, idx + 1);
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	ll x = 1;
	for (int i = 0; i < 20; i++) {
		p3[i] = x;
		x *= 3;
	}

	cin >> N;

	if (N == 0) {
		cout << "NO";
		exit(0);
	}

	solve(0, 0);
	cout << "NO";
}