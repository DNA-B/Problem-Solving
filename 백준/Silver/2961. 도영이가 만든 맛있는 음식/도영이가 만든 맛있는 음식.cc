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
int N, mn = INT_MAX;
vector<pair<int, int>> v;
//=========================//

void solve(pair<int, int> cur, int idx) {
	if (cur.Y > 0)
		mn = min(mn, abs(cur.X - cur.Y));
	if (idx == v.size())
		return;

	for (int i = idx; i < N; i++)
		solve({ cur.X * v[i].X, cur.Y + v[i].Y }, i + 1);
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	int x, y;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		v.push_back({ x, y });
	}

	solve({ 1, 0 }, 0);
	cout << mn;
}