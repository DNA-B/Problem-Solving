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
const int BOUND = 10000 * 10 + 5;
int unused = ROOT + 1;
int T, N;
bool chk[BOUND];
int nxt[BOUND][10];
/***********************/

bool insert(string& s) {
	int cur = ROOT;
	for (auto& c : s) {
		if (chk[cur])
			return false;
		if (nxt[cur][c - '0'] == -1)
			nxt[cur][c - '0'] = unused++;
		cur = nxt[cur][c - '0'];
	}

	if (cur != unused - 1)
		return false;

	chk[cur] = true;
	return true;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> T;

	while (T--) {
		for (int i = 0; i < BOUND; i++)
			fill(nxt[i], nxt[i] + 10, -1);
		fill(chk, chk + BOUND, false);

		unused = ROOT + 1;
		cin >> N;

		string tmp;
		bool flag = true;
		while (N--) {
			cin >> tmp;
			if (!insert(tmp)) flag = false;
		}
		cout << (flag ? "YES\n" : "NO\n");
	}

	return 0;
}