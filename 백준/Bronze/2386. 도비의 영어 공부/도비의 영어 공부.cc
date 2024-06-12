#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/******** MACRO ********/
#define BOUND 1001
#define MOD 1'000'000'007
#define ll long long
#define X first
#define Y second
/***********************/

using namespace std;

/****** VARIABLEs ******/
/***********************/

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	while (1) {
		char want_ch;
		string phrase;
		int alp[26] = { 0 };

		cin >> want_ch;
		cin.ignore();

		if (want_ch == '#')
			break;

		getline(cin, phrase);

		for (auto item : phrase)
			alp[tolower(item) - 'a']++;

		cout << want_ch << " " << alp[want_ch - 'a'] << "\n";
	}

	return 0;
}