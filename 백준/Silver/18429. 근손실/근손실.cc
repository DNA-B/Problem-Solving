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
int N, K, res = 0;
int kits[10], chk[10];
//=========================//

void solve(int cnt, int cur) {
	if (cur < 500)
		return;
	if (cnt == N) {
		res++;
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!chk[i]) {
			chk[i] = 1;
			solve(cnt + 1, cur - K + kits[i]);
			chk[i] = 0;
		}
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> K;

	for (int i = 0; i < N; i++)
		cin >> kits[i];

	solve(0, 500);

	cout << res;
}