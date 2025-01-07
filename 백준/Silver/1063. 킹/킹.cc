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
string ki, st;
pair<int, int> king, stone;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> ki >> st >> N;

	king = { ki[1] - '0', ki[0] - 'A' };
	stone = { st[1] - '0', st[0] - 'A' };

	string order;
	while (N--) {
		int dx, dy;
		auto [kx, ky] = king;
		auto [sx, sy] = stone;

		cin >> order;

		if (order == "R")
			dx = 0, dy = 1;
		else if (order == "L")
			dx = 0, dy = -1;
		else if (order == "B")
			dx = -1, dy = 0;
		else if (order == "T")
			dx = 1, dy = 0;
		else if (order == "RT")
			dx = 1, dy = 1;
		else if (order == "LT")
			dx = 1, dy = -1;
		else if (order == "RB")
			dx = -1, dy = 1;
		else if (order == "LB")
			dx = -1, dy = -1;

		if (kx + dx <= 0 || kx + dx > 8 || ky + dy < 0 || ky + dy >= 8)
			continue;

		if (kx + dx == sx && ky + dy == sy) {
			if (sx + dx <= 0 || sx + dx > 8 || sy + dy < 0 || sy + dy >= 8) // 움직일 위치에 돌이 있다면 같이 이동)
				continue;
			else
				stone = { sx + dx, sy + dy };
		}

		king = { kx + dx, ky + dy };
	}

	string res_king = char((king.Y + 'A')) + to_string(king.X);
	string res_stone = char((stone.Y + 'A')) + to_string(stone.X);
	cout << res_king << '\n' << res_stone;
}