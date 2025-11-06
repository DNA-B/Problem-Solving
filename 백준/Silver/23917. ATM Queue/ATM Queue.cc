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
int T, N, X;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		vector<pair<int, int>> res;

		cin >> N >> X;

		int v;
		for (int i = 1; i <= N; i++) {
			cin >> v;

			bool mod = v % X;
			res.push_back({ v / X + mod, i });
		}

		stable_sort(res.begin(), res.end(),
			[](const pair<int, int> a, const pair<int, int> b) {
				return a.X < b.X;
			});

		cout << "Case #" << tc << ": ";

		for (auto [v, idx] : res)
			cout << idx << ' ';
		cout << '\n';
	}
}