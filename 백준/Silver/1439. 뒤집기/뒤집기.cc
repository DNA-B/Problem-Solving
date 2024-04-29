#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/******** MACRO ********/
#define BOUND 10
#define MAX 1'000'000'001
#define MOD 10000
#define ll long long
#define X first
#define Y second
/***********************/

using namespace std;

/****** VARIABLEs ******/
int zero = 0, one = 0;
char cur = '\0';
string S;
/***********************/

int main() {
	cin.tie(0)->sync_with_stdio(0);

	// freopen("input.txt", "r", stdin);

	cin >> S;

	for (char ch : S) {
		if (ch != cur) {
			if (ch == '1') {
				cur = '1';
				one++;
			}
			else {
				cur = '0';
				zero++;
			}
		}
	}

	cout << min(zero, one);

	return 0;
}