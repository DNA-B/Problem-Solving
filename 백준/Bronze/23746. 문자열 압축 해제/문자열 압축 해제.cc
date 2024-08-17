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
int N, st, en;
string S, res;
map<char, string> m;
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 0; i < N; i++) {
		char to;
		string from;
		cin >> from >> to;
		m[to] = from;
	}

	cin >> S;

	for (int i = 0; i < S.size(); i++)
		res += m[S[i]];

	cin >> st >> en;
	for (int i = st - 1; i < en; i++)
		cout << res[i];

	return 0;
}