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
int cnt_a = 0, res = INT_MAX;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> S;

	for (char ch : S)
		cnt_a += (ch == 'a');

	for (int i = 0; i < S.size(); i++) {
		int a = cnt_a, tmp = 0;
		for (int j = i; j < i + S.size(); j++) {
			if (a == 0) break;
			if (S[j % S.size()] == 'b') tmp++;
			a--;
		}
		res = min(res, tmp);
		if (res == 0) break;
	}

	cout << res;
}