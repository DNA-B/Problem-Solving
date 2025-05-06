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
int N;
int res[4], vis[4];
char board[105][105];
pair<int, int> home, cc;
vector<pair<int, int>> topping[4];
//=========================//

void solve(int top, int cnt, int dist, pair<int, int> cur) {
	if (cnt == 3) {
		dist += abs(cur.X - cc.X) + abs(cur.Y - cc.Y); // 마지막 좌표에서 쿠키크루삥뽕까지 거리 추가
		res[top] = min(res[top], dist);
		return;
	}

	for (int i = 0; i < 3; i++) {
		if (!vis[i]) {
			vis[i] = 1;
			dist += abs(cur.X - topping[top][i].X) + abs(cur.Y - topping[top][i].Y);
			solve(top, cnt + 1, dist, topping[top][i]);
			dist -= abs(cur.X - topping[top][i].X) + abs(cur.Y - topping[top][i].Y);
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
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			switch (board[i][j]) {
				case 'H':
					home = { i, j };
					break;
				case '#':
					cc = { i, j };
					break;
				case 'J':
					topping[0].push_back({ i, j });
					break;
				case 'C':
					topping[1].push_back({ i, j });
					break;
				case 'B':
					topping[2].push_back({ i, j });
					break;
				case 'W':
					topping[3].push_back({ i, j });
					break;
			}
		}
	}

	fill(res, res + 4, INF);
	for (int i = 0; i < 4; i++)
		solve(i, 0, 0, home);

	int idx = min_element(res, res + 4) - res;
	switch (idx) {
		case 0:
			cout << "Assassin";
			break;
		case 1:
			cout << "Healer";
			break;
		case 2:
			cout << "Mage";
			break;
		case 3:
			cout << "Tanker";
			break;
	}
}