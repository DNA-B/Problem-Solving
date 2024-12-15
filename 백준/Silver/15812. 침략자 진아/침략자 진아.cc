#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
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
int N, M, mn = INT_MAX;
char board[25][25];
vector<pair<int, int>> house, zero;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];

			if (board[i][j] == '1')
				house.push_back({ i, j });
			else
				zero.push_back({ i, j });
		}
	}

	for (auto z1 : zero) {
		for (auto z2 : zero) {
			if (z1 == z2)
				continue;

			int mx = -1;
			for (auto h : house)
				mx = max(mx, min(abs(z1.X - h.X) + abs(z1.Y - h.Y), abs(z2.X - h.X) + abs(z2.Y - h.Y)));
			mn = min(mn, mx);
		}
	}

	cout << mn;
}
