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
int N, M, res = INT_MAX;
int vis[15];
vector<pair<int, int>> house, chick, choices;
//=========================//

void solve(int idx, int cnt) {
	if (cnt == M) {
		int total = 0;
		for (auto& [x1, y1] : house) {
			int mn = INT_MAX;
			for (auto& [x2, y2] : choices)
				mn = min(mn, abs(x1 - x2) + abs(y1 - y2));
			total += mn;
		}
		res = min(res, total);
		return;
	}

	for (int i = idx; i < chick.size(); i++) {
		if (!vis[i]) {
			vis[i] = 1;
			choices.push_back(chick[i]);
			solve(i + 1, cnt + 1);
			choices.pop_back();
			vis[i] = 0;
		}
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> M;

	int x;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> x;
			if (x == 1)
				house.push_back({ i, j });
			else if (x == 2)
				chick.push_back({ i, j });
		}
	}

	solve(0, 0);
	cout << res;
}