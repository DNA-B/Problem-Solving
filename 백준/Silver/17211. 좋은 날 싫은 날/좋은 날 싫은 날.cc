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

int N, cur;
double gg, gb, bg, bb;
double mem[105][2];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> cur;
	cin >> gg >> gb >> bg >> bb;

	if (!cur) // good
		mem[0][0] = 1.0;
	else // bad
		mem[0][1] = 1.0;

	for (int i = 1; i <= N; i++) {
		mem[i][0] = (mem[i - 1][0] * gg) + (mem[i - 1][1] * bg);
		mem[i][1] = (mem[i - 1][0] * gb) + (mem[i - 1][1] * bb);
	}

	cout << int(mem[N][0] * 1000) << '\n' << int(mem[N][1] * 1000);
}