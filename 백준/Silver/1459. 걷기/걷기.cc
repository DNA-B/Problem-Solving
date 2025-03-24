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
ll X, Y, W, S;
ll c1, c2;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> X >> Y >> W >> S;

	c1 = (X + Y) * W;
	c2 = min(X, Y) * S; // 대각선만큼 가고
	c2 += min(abs(X - Y) * W,
		(abs(X - Y) % 2 == 1 ? (abs(X - Y) - 1) * S + W : abs(X - Y) * S));
	// 홀수면 짝수만큼 대각선 -> W만큼 이동 / 짝수면 대각선으로 전부 이동
	cout << min(c1, c2);
}