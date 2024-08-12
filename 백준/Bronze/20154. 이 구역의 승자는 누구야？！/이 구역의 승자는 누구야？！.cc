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
int res = -1;
string S;
map<char, int> m = {
	{'A', 3 },{'B', 2 },{'C', 1 }, {'D', 2 },{'E', 3 },{'F', 3 },
	{'G', 3 },{'H', 3 },{'I', 1 }, {'J', 1 },{'K', 3 },{'L', 1 },
	{'M', 3 },{'N', 3 },{'O', 1 }, {'P', 2 },{'Q', 2 },{'R', 2 },
	{'S', 1 },{'T', 2 },{'U', 1 }, {'V', 1 },{'W', 2 },{'X', 2 },
	{'Y', 2 },{'Z', 1 } };
/***********************/

void solve(vector<int> v) {
	if (v.size() == 1) {
		res = v[0] % 10;
		return;
	}

	vector<int> tmp;
	for (int i = 0; i < v.size(); i += 2) {
		if (i == v.size() - 1) tmp.push_back(v[i] % 10);
		else tmp.push_back((v[i] + v[i + 1]) % 10);
	}
	solve(tmp);
}

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> S;

	vector<int> v;
	for (int i = 0; i < S.size(); i += 2) {
		if (i == S.size() - 1) v.push_back(m[S[i]]);
		else v.push_back((m[S[i]] + m[S[i + 1]]) % 10);
	}

	solve(v);
	cout << ((res & 1) ? "I'm a winner!" : "You're the winner?");
	return 0;
}