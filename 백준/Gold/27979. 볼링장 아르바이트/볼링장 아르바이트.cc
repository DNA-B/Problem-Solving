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
int N, idx;
vector<int> ball, W;
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	ball.resize(N);
	for (auto& w : ball)
		cin >> w;

	W = ball, idx = N - 1;
	sort(W.begin(), W.end());

	for (int i = N - 1; i >= 0; i--) {
		if (ball[i] == W[idx])
			idx--;
	}

	cout << idx + 1;
	return 0;
}