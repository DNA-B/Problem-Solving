#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define BOUND 101
#define INF 0x3f3f3f3f
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int A, B, N, W;
stack<pair<int, int>> res;
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> A >> B >> N >> W;

	for (int i = 1; i < N; i++) {
		int food = (A * i) + (B * (N - i));

		if (food == W)
			res.push({ i, N - i });
	}

	if (res.size() > 1 || res.empty())
		cout << -1;
	else
		cout << res.top().X << " " << res.top().Y;

	return 0;
}