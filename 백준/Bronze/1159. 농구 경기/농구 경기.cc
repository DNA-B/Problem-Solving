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
int N;
bool is_give_up = true;
map<char, int> m;
/***********************/

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	while (N--) {
		string first_name;

		cin >> first_name;
		m[first_name[0]]++;
	}

	for (auto item : m) {
		if (item.second >= 5) {
			cout << item.first;
			is_give_up = false;
		}
	}

	if (is_give_up)
		cout << "PREDAJA";

	return 0;
}