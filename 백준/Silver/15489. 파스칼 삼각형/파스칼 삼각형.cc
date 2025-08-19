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
int R, C, W;
int mem[35][35];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	for (int i = 1; i <= 30; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1 || j == i)
				mem[i][j] = 1;
			else
				mem[i][j] = mem[i - 1][j - 1] + mem[i - 1][j];
		}
	}

	cin >> R >> C >> W;

	ll total = 0;
	for (int i = 0; i < W; i++) {
		for (int j = 0; j <= i; j++)
			total += mem[R + i][C + j];
	}

	cout << total;
}