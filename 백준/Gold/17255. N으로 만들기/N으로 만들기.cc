#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_set>
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
string N;
map<set<string>, bool> um;
/***********************/

void solve(int l, int r, string cur, set<string> path) {
	if (cur.length() >= N.length()) {
		if (cur == N) um[path] = true;
		return;
	}

	if (l > 0) {
		path.insert(N[l - 1] + cur);
		solve(l - 1, r, N[l - 1] + cur, path);
		path.erase(N[l - 1] + cur);
	}
	if (r < N.length()) {
		path.insert(cur + N[r + 1]);
		solve(l, r + 1, cur + N[r + 1], path);
		path.erase(cur + N[r + 1]);
	}
}

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 0; i < N.size(); i++) {
		string tmp = "";
		set<string> path_tmp = { tmp + N[i] };
		solve(i, i, tmp + N[i], path_tmp);
	}

	cout << um.size();
	return 0;
}