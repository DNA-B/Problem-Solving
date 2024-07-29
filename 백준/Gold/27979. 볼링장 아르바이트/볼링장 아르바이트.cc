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
int N, x, len = 0;
int cur, cur_idx;
vector<int> w;
vector<pair<int, int>> ball;
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> x;
		ball.push_back({ x, i });
		w.push_back(x);
	}

	cur = N - 1, cur_idx = INT_MAX;
	sort(w.begin(), w.end());

	for (int i = N - 1; i >= 0; i--) {
		if (w[cur] == ball[i].X && cur_idx > ball[i].Y) {
			cur_idx = ball[i].Y;
			cur--, len++;
		}
	}

	cout << N - len;
	return 0;
}