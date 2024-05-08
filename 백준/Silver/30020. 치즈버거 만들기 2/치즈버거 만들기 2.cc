#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/******** MACRO ********/
#define BOUND 100'001
#define MAX 1'000'000'001
#define MOD 10000
#define ll long long
#define X first
#define Y second
/***********************/

using namespace std;

/****** VARIABLEs ******/
int A, B, cnt = 0;
string hamburger;
vector<string> res;
/***********************/

int main() {
	cin.tie(0)->sync_with_stdio(0);

	// freopen("input.txt", "r", stdin);

	cin >> A >> B;

	hamburger = "aba";
	A -= 2;
	B -= 1;
	cnt++;

	while (A > 0 and B > 0) {
		if (A == B) {
			hamburger += "ba";
			A--;
			B--;
		}
		else {
			res.push_back(hamburger);
			hamburger = "aba";
			A -= 2;
			B -= 1;
			cnt++;
		}
	}

	res.push_back(hamburger);

	if (A == 0 and B == 0) {
		cout << "YES\n";
		cout << cnt << "\n";

		for (string s : res)
			cout << s << "\n";
	}
	else {
		cout << "NO";
	}

	return 0;
}