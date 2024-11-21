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
int P, W;
int cur = 0;
int res = 0;
int match[2][27] = { { 1, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4 },
				{ 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9 } };
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> P >> W;
	cin.ignore();
	getline(cin, S);

	for (int i = 0; i < S.length(); ++i) {
		int idx = -1;

		if ('A' <= S[i] && S[i] <= 'Z')
			idx = (S[i] - 'A') + 1;
		if (S[i] == ' ')
			idx = 0;

		if (cur == match[1][idx] && idx != 0)
			res += W;
		res += match[0][idx] * P;
		cur = match[1][idx];
	}

	cout << res;
}