#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
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
int T;
int R, C, K;
map<pair<int, int>, bool> monsters;
//=========================//

bool is_valid(int x1, int y1, int x2, int y2) {
	for (int i = x1; i <= x2; i++) {
		for (int j = y1; j <= y2; j++) {
			if (monsters[{i, j}]) // 몬스터가 있는지 확인
				return false;
		}
	}
	return true;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int cnt = 0;

		monsters.clear();
		cin >> R >> C >> K;

		for (int x, y, i = 0; i < K; i++) {
			cin >> x >> y;
			monsters[{ x, y }] = true;
		}

		for (int i = 0; i < 10; i++) {
			for (int row = 0; row < R - i; row++) {
				for (int col = 0; col < C - i; col++) {
					if (is_valid(row, col, row + i, col + i))
						cnt++;
				}
			}
		}

		cout << "Case #" << tc << ": " << cnt << '\n';
	}
}