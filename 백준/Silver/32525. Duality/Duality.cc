#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_set>
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
int T, N;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> T;

	while (T--) {
		vector<pair<int, int>> points;

		cin >> N;

		for (int x, y, i = 0; i < N; i++) {
			cin >> x >> y;
			points.push_back({ x, y });
		}

		for (int i = 0; i < N; ++i) {
			auto [x, y] = points[i];
			cout << i + 1 << ' ' << x + 1 << ' ' << y + 500000000 << '\n';
		}
	}
}