#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define BOUND 201
#define INF 0x3f3f3f3f
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int K, R;
string s;
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> K >> s;
	R = s.size() / K;

	for (int i = 1; i < R; i += 2)
		reverse(s.begin() + (K * i), s.begin() + (K * i) + K);

	for (int i = 0; i < K; i++) {
		for (int j = 0; j < R; j++)
			cout << s[K * j + i];
	}

	return 0;
}