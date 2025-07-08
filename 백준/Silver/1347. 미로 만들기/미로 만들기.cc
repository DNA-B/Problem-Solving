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
int x = 50, y = 50;
int mnx = 50, mxx = 50, mny = 50, mxy = 50;
char board[105][105];
pair<int, int> dir[] = { {1, 0}, {0, -1}, {-1, 0}, {0, 1} }; // R -> +1, L -> -1
string S;
//=========================//


int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> S;

	int cur_dir = 0, tmp_x, tmp_y;
	board[x][y] = '.';
	for (char ch : S) {
		switch (ch) {
			case 'R':
				cur_dir = (cur_dir + 1) % 4;
				break;
			case 'L':
				cur_dir = ((cur_dir - 1) + 4) % 4;
				break;
			case'F':
				x += dir[cur_dir].X;
				y += dir[cur_dir].Y;
				board[x][y] = '.';
				mnx = min(mnx, x);
				mxx = max(mxx, x);
				mny = min(mny, y);
				mxy = max(mxy, y);
				break;
		}
	}

	for (int i = mnx; i <= mxx; i++) {
		for (int j = mny; j <= mxy; j++)
			cout << (board[i][j] == '.' ? board[i][j] : '#');
		cout << '\n';
	}
}