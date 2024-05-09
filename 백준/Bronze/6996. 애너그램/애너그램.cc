#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/******** MACRO ********/
#define BOUND 100001
#define MAX 1'000'000'001
#define MOD 10000
#define ll long long
#define X first
#define Y second
/***********************/

using namespace std;

/****** VARIABLEs ******/
int T;
string A, B;
/***********************/

bool is_anagram(string a, string b) {
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	return a == b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> T;

	while (T--) {
		cin >> A >> B;

		if (is_anagram(A, B))
			cout << A << " & " << B << " are anagrams.\n";
		else
			cout << A << " & " << B << " are NOT anagrams.\n";
	}

	return 0;
}