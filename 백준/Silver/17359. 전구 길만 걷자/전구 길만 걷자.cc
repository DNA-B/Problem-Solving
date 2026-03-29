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
int N, mn = INT_MAX;
int vis[15], diff[15];
string bulbs[15];
//=========================//

void solve(int cnt, int cur_diff, char last) {
	if (cnt == N) {
		mn = min(mn, cur_diff);
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!vis[i]) {
			vis[i] = 1;

			bool flag = false;
			if (cnt > 0 && (last != bulbs[i][0]))
				flag = true;

			solve(cnt + 1, cur_diff + flag + diff[i], bulbs[i].back());
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

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> bulbs[i];

		for (int j = 0; j < bulbs[i].length() - 1; j++) // 각 세트별 01, 10 미리 계산
			diff[i] += (bulbs[i][j] != bulbs[i][j + 1]);
	}

	solve(0, 0, '\0');
	cout << mn;
}