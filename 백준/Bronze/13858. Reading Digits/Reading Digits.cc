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
int k, pos;
string cur;
/***********************/

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> k >> pos >> cur;

	while (k--) {
		string tmp = "";

		for (int i = 0; i < cur.size(); i += 2) {
			for (int rep = 0; rep < cur[i] - '0'; rep++)
				tmp += cur[i + 1];
		}

		cur = tmp;
	}

	cout << cur[pos];
	return 0;
}