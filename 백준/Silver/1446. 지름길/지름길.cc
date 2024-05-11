#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/******** MACRO ********/
#define BOUND 10005
#define MAX 1'000'000'001
#define MOD 10000
#define ll long long
#define X first
#define Y second
/***********************/

using namespace std;

/****** VARIABLEs ******/
int N, D;
int mem[BOUND];
vector<pair<int, int>> board[BOUND];
/***********************/

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> D;

	fill(mem, mem + BOUND, INT_MAX);

	while (N--) {
		int st, en, l;
		cin >> st >> en >> l;

		if (en > D)
			continue;

		board[en].push_back({ st, l }); // en으로 가는 지름길 st의 길이가 l
	}

	mem[0] = 0;
	for (int i = 1; i <= D; i++) {
		mem[i] = mem[i - 1] + 1;

		if (not board[i].empty()) {
			for (auto item : board[i]) // item.first : i로 이어진 지름길 시작점, item.second 지름길 길이
				mem[i] = min(mem[i], mem[item.first] + item.second);
		}
	}

	cout << mem[D];

	return 0;
}