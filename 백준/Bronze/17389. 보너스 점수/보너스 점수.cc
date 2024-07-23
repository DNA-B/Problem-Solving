#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define INF 0x3f3f3f3f
#define LLINF 1e18
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N, total = 0, bonus = 0;
string S;
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> S;

	for (int i = 0; i < S.size(); i++) {
		if (S[i] == 'O')
			total += (i + 1) + (bonus++);
		else
			bonus = 0;
	}

	cout << total;
	return 0;
}