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
int N, res = 0;
pair<int, int> peoples[25];
//=========================//

void solve(int cur_health, int cur_happy, int idx) {
	res = max(res, cur_happy);

	if (idx == N)
		return;

	for (int i = idx; i < N; i++) {
		auto [health, happy] = peoples[i];

		if (cur_health - health <= 0)
			continue;

		solve(cur_health - health, cur_happy + happy, i + 1);
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> peoples[i].X;

	for (int i = 0; i < N; i++)
		cin >> peoples[i].Y;

	solve(100, 0, 0);
	cout << res;
}