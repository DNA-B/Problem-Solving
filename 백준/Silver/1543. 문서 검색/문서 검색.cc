#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/******** MACRO ********/
#define BOUND 200001
#define MOD 1'000'000'007
#define ll long long
#define X first
#define Y second
/***********************/

using namespace std;

/****** VARIABLEs ******/
string doc, word;
int cnt = 0;
/***********************/

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	getline(cin, doc);
	getline(cin, word);

	for (int i = 0; i < doc.size(); i++) {
		if (doc.substr(i, word.size()) == word) {
			cnt++;
			i += word.size() - 1;
		}
	}

	cout << cnt;

	return 0;
}