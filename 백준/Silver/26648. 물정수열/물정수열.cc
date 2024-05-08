#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/******** MACRO ********/
#define BOUND 200'001
#define MAX 1'000'000'001
#define MOD 10000
#define ll long long
#define X first
#define Y second
/***********************/

using namespace std;

/****** VARIABLEs ******/
int N, cur = -1;
bool flag = true;
vector <vector<int>> score(3, vector<int>(BOUND, 0));
/***********************/

int main() {
	cin.tie(0)->sync_with_stdio(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < N; j++)
			cin >> score[i][j];

	for (int i = 0; i < N; i++) {
		int lo = min({ score[0][i], score[1][i], score[2][i] });
		int hi = max({ score[0][i], score[1][i], score[2][i] });

		if (cur < lo)
			cur = lo;
		else if (lo <= cur and cur < hi)
			cur += 1;
		else if (hi <= cur)
			flag = false;
	}

	cout << (flag ? "YES" : "NO");

	return 0;
}