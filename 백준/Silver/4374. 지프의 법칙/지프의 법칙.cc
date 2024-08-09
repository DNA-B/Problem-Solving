#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

/******** MACRO ********/
#define INT_INF 0x3f3f3f3f
#define LL_INF 1e18
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N;
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	while (cin >> N) {
		map<string, int> m;
		string phrase;
		int cnt = 0;

		cin.ignore();
		while (1) {
			string tmp = "";
			getline(cin, phrase);

			if (phrase == "EndOfText")
				break;

			for (char& ch : phrase) {
				if (('A' <= ch && ch <= 'Z') || ('a' <= ch && ch <= 'z'))
					tmp += tolower(ch);
				else {
					m[tmp]++;
					tmp = "";
				}
			}

			if (tmp != "")
				m[tmp]++;
		}

		for (auto item : m) {
			if (item.Y == N) {
				cout << item.X << "\n";
				cnt++;
			}
		}

		if (cnt == 0)
			cout << "There is no such word.\n";
		cout << "\n";
	}

	return 0;
}