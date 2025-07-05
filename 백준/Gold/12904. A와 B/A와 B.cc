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
string S, T;
//=========================//

void solve(string cur) {
	if (cur == S) {
		cout << 1;
		exit(0);
	}

	if (cur.size() < S.size())
		return;

	if (cur.back() == 'A') {
		cur.pop_back();
		solve(cur);
	}
	else if (cur.back() == 'B') {
		cur.pop_back();
		reverse(cur.begin(), cur.end());
		solve(cur);
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> S >> T;
	solve(T);
	cout << 0;
}