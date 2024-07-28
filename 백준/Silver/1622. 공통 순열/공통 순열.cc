#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define INF 0x3f3f3f3f
#define LLINF 1e18
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
string a, b;
int cnt1[26], cnt2[26];
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	while (getline(cin, a) && getline(cin, b)) {
		fill(cnt1, cnt1 + 26, 0);
		fill(cnt2, cnt2 + 26, 0);

		for (char ch : a)
			cnt1[ch - 'a']++;
		for (char ch : b)
			cnt2[ch - 'a']++;

		for (int i = 0; i < 26; i++) {
			int cnt = min(cnt1[i], cnt2[i]);
			while (cnt--)
				cout << (char)('a' + i);
		}
		cout << "\n";
	}

	return 0;
}