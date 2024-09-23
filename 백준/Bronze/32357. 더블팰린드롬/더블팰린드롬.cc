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
int N, cnt = 0;
string s[10005];
/***********************/

bool is_pal(string a) {
	for (int i = 0; i < a.size() / 2; i++) {
		if (a[i] != a[a.size() - (i + 1)])
			return false;
	}
	return true;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> s[i];
		cnt += is_pal(s[i]);
	}

	cout << cnt * (cnt - 1);
	return 0;
}