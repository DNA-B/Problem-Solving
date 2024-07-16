#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define BOUND 20
#define INF 0x3f3f3f3f
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
ll N, W;
ll cur_coin = 0;
ll price[BOUND];
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> W;

	for (int i = 0; i < N; i++)
		cin >> price[i];

	for (int i = 0; i < N; i++) {
		if (i == N - 1 || price[i] > price[i + 1]) {
			W += price[i] * cur_coin;
			cur_coin = 0;
		}
		else if (price[i] < price[i + 1]) {
			cur_coin += W / price[i];
			W -= price[i] * (W / price[i]);
		}
	}

	cout << W;
	return 0;
}