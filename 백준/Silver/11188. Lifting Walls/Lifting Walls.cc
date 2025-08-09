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
const int ALL = 15; // 0111
int L, W, N, R, mn = INT_MAX;
int cranes[35];
pair<double, double> wall[4];
//=========================//

void solve(int cur, int idx, int cnt) {
	if (cur == ALL) {
		mn = min(mn, cnt);
		return;
	}
	if (cnt == N || cnt > mn)
		return;

	for (int i = idx; i < N; i++) {
		int tmp = cur;
		tmp |= cranes[i];
		solve(tmp, i + 1, cnt + 1);
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> L >> W >> N >> R;

	wall[0] = { -L / 2.0, 0 };
	wall[1] = { L / 2.0, 0 };
	wall[2] = { 0, -W / 2.0 };
	wall[3] = { 0, W / 2.0 };

	int x, y;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;

		for (int j = 0; j < 4; j++) {
			auto [wx, wy] = wall[j];

			double dist = pow(wx - x, 2) + pow(wy - y, 2);
			if (dist <= R * R)
				cranes[i] |= (1 << j);
		}
	}

	solve(0, 0, 0);

	if (mn == INT_MAX)
		cout << "Impossible";
	else
		cout << mn;
}