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
int N, mn = INT_MAX;
string S;
//=========================//

void check(char color) {
	bool flag = false;
	int cnt = 0;

	for (int i = 0; i < N; i++) {
		if (S[i] == color) flag = true;
		else if (flag && S[i] != color) cnt++;
	}

	mn = min(mn, cnt);
	flag = false;
	cnt = 0;

	for (int i = N - 1; i >= 0; i--) {
		if (S[i] == color) flag = true;
		else if (flag && S[i] != color) cnt++;
	}

	mn = min(mn, cnt);
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> S;
	check('B');
	check('R');
	cout << mn;
}