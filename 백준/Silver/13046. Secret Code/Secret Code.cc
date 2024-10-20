#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define PI 3.1415926535897932
#define MOD 1000000007
#define INT_INF 0x3f3f3f3f
#define LL_INF 1e18
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N;
string S, cmp;
unordered_map<char, int> um;
/***********************/


int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> S >> N;

	while (N--) {
		for (char ch : S)
			um[ch]++;

		int cor = 0, diff = 0;
		cin >> cmp;

		for (int i = 0; i < S.size(); i++) {
			if (um[cmp[i]] > 0 && cmp[i] == S[i]) {
				um[cmp[i]]--;
				cor++;
			}
			else if (um[cmp[i]] > 0 && cmp[i] != S[i]) {
				diff++;
			}
		}

		cout << cor << ' ' << diff << '\n';
	}

	return 0;
}