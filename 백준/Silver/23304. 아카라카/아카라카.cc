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
string S;
//=========================//

bool is_AKARAKA(int st, int en) {
	if (st == en)
		return true;

	for (int i = st; i < en / 2; i++)
		if (S[i] != S[en - (i + 1)])
			return false;

	bool chk_left = is_AKARAKA(st, (st + en) / 2);
	bool chk_right = is_AKARAKA((st + en) / 2 + 1, en);
	return chk_left && chk_right;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> S;
	cout << (is_AKARAKA(0, S.length()) ? "AKARAKA" : "IPSELENTI");
}