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
int N;
ll res = 0;
unordered_map<int, int> xs, ys;
vector<pair<int, int>> xy;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	int x, y;
	while (N--) {
		cin >> x >> y;
		xy.push_back({ x, y });
		xs[x]++;
		ys[y]++;
	}

	for (auto& [x, y] : xy) {
		ll nx = xs[x] - 1;
		ll ny = ys[y] - 1;
		res += nx * ny;
	}

	cout << res;
}