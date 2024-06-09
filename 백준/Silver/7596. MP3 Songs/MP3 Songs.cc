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
/***********************/

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	while (1) {
        string song;
        set<string> mp3;
        
		cin >> N;
		cin.ignore();

		if (N == 0)
			break;

		cout << scene++ << "\n";

		for (int i = 0; i < N; i++) {
			getline(cin, song);
			mp3.insert(song);
		}

		for (string item : mp3)
			cout << item << "\n";
	}

	return 0;
}