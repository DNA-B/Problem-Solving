#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

/******** MACRO ********/
#define PI 3.1415926535897932
#define MOD 1000000007
#define INT_INF 0x3f3f3f3f
#define LL_INF 1e18
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int K;
bool vis[26];
string S, res = "";
/***********************/

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> S >> K;

	for (auto& ch : S)
		ch = tolower(ch);

	char tmp = S[0];
	int cnt = 1;
	for (int i = 1; i < S.size(); i++) {
		if (tmp != S[i]) {
			if (!vis[tmp - 'a'])
				res += (cnt >= K ? "1" : "0");
			vis[tmp - 'a'] = true;
			cnt = 0;
			tmp = S[i];
		}
		cnt++;
	}

	if (!vis[tmp - 'a'])
		res += (cnt >= K ? "1" : "0");
	cout << res;
	return 0;
}