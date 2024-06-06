#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/******** MACRO ********/
#define BOUND 10
#define MOD 1'000'000'007
#define ll long long
#define X first
#define Y second
/***********************/

using namespace std;

/****** VARIABLEs ******/
int N, T, P;
int t_shirt[10];
/***********************/

void get_t_shirt() {
	int cnt = 0;

	for (int i = 0; i < 6; i++) {
		cnt += (t_shirt[i] / T);

		if (t_shirt[i] % T > 0)
			cnt++;
	}

	cout << cnt << "\n";
	return;
}

void get_pen() {
	cout << N / P << " " << N % P;
	return;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 0; i < 6; i++)
		cin >> t_shirt[i];

	cin >> T >> P;

	get_t_shirt();
	get_pen();

	return 0;
}