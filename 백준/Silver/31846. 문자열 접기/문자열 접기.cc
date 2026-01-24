#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

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
int N, Q;
string S;
//=========================//

int solve(string s) {
	int mx = 0;
	for (int i = 1; i < s.length(); i++) {
		int match = 1, cnt = 0;
		for (int j = i - 1; j >= 0; j--) {
			if (j + match >= s.length())
				break;
			if (s[j] == s[j + match])
				cnt++;
			match += 2;
		}
		mx = max(mx, cnt);
	}

	return mx;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> S >> Q;

	int l, r;
	while (Q--) {
		cin >> l >> r;
		cout << solve(S.substr(l - 1, r - l + 1)) << '\n';
	}
}