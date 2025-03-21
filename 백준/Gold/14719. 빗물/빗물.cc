#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include<unordered_set>
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
int H, W, res = 0;
bool board[505][505];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> H >> W;

	for (int x, i = 0; i < W; i++) {
		cin >> x;
		for (int j = 0; j < x; j++)
			board[j][i] = true;
	}

	for (int x, i = 0; i < H; i++) {
		bool flag = false;
		int prev = 0;
		for (int j = 0; j < W; j++) {
			if (flag && board[i][j]) {
				res += j - (prev + 1);
				prev = j;
			}
			else if (board[i][j]) {
				flag = true;
				prev = j;
			}
		}
	}

	cout << res;
}