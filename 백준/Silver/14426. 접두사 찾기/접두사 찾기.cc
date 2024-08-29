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
const int ROOT = 1;
const int BOUND = 500 * 10000 + 5;
int unused = 2;
int N, M, res = 0;
int nxt[BOUND][26];
/***********************/

void insert(string& s) {
	int cur = ROOT;
	for (auto& c : s) {
		if (nxt[cur][c - 'a'] == -1)
			nxt[cur][c - 'a'] = unused++;
		cur = nxt[cur][c - 'a'];
	}
}

bool find(string& s) {
	int cur = ROOT;
	for (auto& c : s) {
		if (nxt[cur][c - 'a'] == -1)
			return false;
		cur = nxt[cur][c - 'a'];
	}
	return true;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	for (int i = 0; i < BOUND; i++)
		fill(nxt[i], nxt[i] + 26, -1);

	cin >> N >> M;

	while (N--) {
		string tmp;
		cin >> tmp;
		insert(tmp);
	}

	while (M--) {
		string tmp;
		cin >> tmp;
		res += find(tmp);
	}

	cout << res;
	return 0;
}