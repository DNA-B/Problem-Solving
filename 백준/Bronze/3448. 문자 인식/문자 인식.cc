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
int T;
string s;
/***********************/

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> T;
	cin.ignore();
	cout << fixed;

	while (T--) {
		vector<string> v;
		double total_len = 0, error_cnt = 0, error_rate;

		while (true) {
			getline(cin, s);

			if (s.empty())
				break;
			else
				v.push_back(s);
		}

		for (string item : v) {
			total_len += item.size();

			for (char ch : item)
				error_cnt = (ch == '#' ? error_cnt : error_cnt + 1);
		}

		error_rate = 100 * error_cnt / total_len;
		error_rate = round(10 * error_rate) / 10;

		if (int(error_rate) == error_rate)
			cout.precision(0);
		else
			cout.precision(1);

		cout << "Efficiency ratio is " << error_rate << "%.\n";
	}

	return 0;
}