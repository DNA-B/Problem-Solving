#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/******** MACRO ********/
#define BOUND 10
#define MOD 1'000'000'007
#define ll long long
#define X first
#define Y second
/***********************/

using namespace std;

/****** VARIABLEs ******/
int N, mail;
string word;
set<string> s;
/***********************/


int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> word;
		s.insert(word);
	}

	cin >> mail;

	for (int i = 1; i <= mail; i++) {
		int cnt = 0;
		vector<string> wrong_word;

		while (1) {
			cin >> word;

			if (word == "-1")
				break;

			if (s.find(word) == s.end()) {
				wrong_word.push_back(word);
				cnt++;
			}
		}

		if (cnt == 0)
			cout << "Email " << i << " is spelled correctly.\n";
		else {
			cout << "Email " << i << " is not spelled correctly.\n";

			for (string word : wrong_word)
				cout << word << "\n";
		}
	}

	cout << "End of Output";

	return 0;
}