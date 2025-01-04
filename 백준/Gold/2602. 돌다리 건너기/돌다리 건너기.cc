#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
//========= MACRO =========//
#define PI 3.1415926535897932
#define INF 0x3f3f3f3f
#define LL_INF 1e18
#define ll long long
#define X first
#define Y second
//=========================//

//======= VARIABLEs =======//
int mem[25][2][105];
string scroll, bridge[2];
//=========================//

int solve(int cur_sc, bool cur_brid, int idx) {
	if (cur_sc == scroll.size())
		return 1;

	int& cnt = mem[cur_sc][cur_brid][idx];

	if (cnt != -1) return cnt;
	else cnt = 0;

	for (int i = idx; i < bridge[0].size(); i++) {
		if (bridge[cur_brid][i] == scroll[cur_sc])
			cnt += solve(cur_sc + 1, !cur_brid, i + 1);
	}

	return cnt;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> scroll >> bridge[0] >> bridge[1];
	memset(mem, -1, sizeof(mem));
	cout << solve(0, 0, 0) + solve(0, 1, 0);
}