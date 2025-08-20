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
int N, o = 0, e = 0;
int res = 0;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	for (int x, i = 0; i < N; ++i) {
		cin >> x;
		(x & 1) ? o++ : e++;
	}

	while (o > e) {
		o -= 2;
		e++;
	}

	if (e > o + 1)
		res = o * 2 + 1;
	else
		res = o + e;

	cout << res;
}