#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/******** MACRO ********/
#define BOUND 5000001
#define MOD 1'000'000'007
#define ll long long
#define X first
#define Y second
/***********************/

using namespace std;

/****** VARIABLEs ******/
int N;
ll total = 0;
/***********************/


int main() {
	cin.tie(0)->sync_with_stdio(0);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	string tmp = "";
	for (int i = 0; i < N; i++) {
		char ch;

		cin >> ch;

		if ('0' <= ch && ch <= '9') {
			tmp += ch;

			if (tmp.length() == 6) {
				total += stoi(tmp);
				tmp = "";
			}
		}
		else {
			if (!tmp.empty())
				total += stoi(tmp);
			tmp = "";
		}
	}

	if (!tmp.empty())
		total += stoi(tmp);

	cout << total;

	return 0;
}