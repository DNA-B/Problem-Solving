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
int N, cnt = 0;
int of = 0, ot = 0, tf = 0;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	string s;
	for (int i = 0; i < N; i++) {
		cin >> s;
		if (s == "1/4")
			of++;
		else if (s == "1/2")
			ot++;
		else
			tf++;
	}

	if (tf > 0 && of > 0) { // 1/4 + 3/4
		int x = min(tf, of);
		cnt += x;
		tf -= x;
		of -= x;
	}

	cnt += tf;
	cnt += (ot / 2);
	ot %= 2;

	if (ot == 1) { // 1/4 + 1/4 + 1/2
		cnt++;
		of = max(0, of - 2);
	}

	cnt += (of / 4) + (of % 4 != 0);
	cout << cnt;
}