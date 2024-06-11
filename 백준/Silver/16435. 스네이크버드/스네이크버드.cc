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
int N, L;
vector<int> v(BOUND);
/***********************/

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> L;

	for (int& apple : v)
		cin >> apple;

	v.resize(N);
	sort(v.begin(), v.end());

	for (int apple : v) {
		if (L >= apple)
			L++;
		else
			break;
	}

	cout << L;

	return 0;
}