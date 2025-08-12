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
int N, res = INT_MAX;
int board[105][105];
pair<int, int> SN;
vector<pair<int, int>> regions;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	int x, y;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2)
				SN = { i, j };
			if (board[i][j] == 1)
				regions.push_back({ i, j });
		}
	}

	bool flag = (SN.X + SN.Y) & 1;
	for (auto& [x, y] : regions) {
		if (((x + y) & 1) != flag) {
			cout << "Shorei";
			exit(0);
		}
	}

	if (regions.empty()) {
		cout << "Undertaker" << '\n' << 0;
		exit(0);
	}

	sort(regions.begin(), regions.end());

	do {
		int t = max(abs(SN.X - regions[0].X), abs(SN.Y - regions[0].Y));
		for (int i = 1; i < regions.size(); i++) {
			auto& [x1, y1] = regions[i];
			auto& [x2, y2] = regions[i - 1];
			t += max(abs(x1 - x2), abs(y1 - y2));
		}
		res = min(res, t);

	} while (next_permutation(regions.begin(), regions.end()));

	cout << "Undertaker" << '\n' << res;
}