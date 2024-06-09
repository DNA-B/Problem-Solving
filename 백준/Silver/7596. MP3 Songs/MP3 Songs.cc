#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/******** MACRO ********/
#define BOUND 100001
#define MOD 1'000'000'007
#define ll long long
#define X first
#define Y second
/***********************/

using namespace std;

/****** VARIABLEs ******/
int N, scene = 1;
vector<string> mp3;
/***********************/

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	while (1) {
		cin >> N;
		cin.ignore();

		if (N == 0)
			break;

		mp3.resize(N);
		cout << scene++ << "\n";

		for (string& song : mp3)
			getline(cin, song);

		sort(mp3.begin(), mp3.end());

		for (string item : mp3)
			cout << item << "\n";
	}

	return 0;
}