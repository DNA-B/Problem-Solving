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
int N;
int cnt = 0;
int game[BOUND];
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> game[i];

	for (int i = N - 1; i > 0; i--) {
		if (game[i] <= game[i - 1]) {
			cnt += (game[i - 1] - game[i]) + 1;
			game[i - 1] -= (game[i - 1] - game[i]) + 1;
		}
	}

	cout << cnt;
	return 0;
}