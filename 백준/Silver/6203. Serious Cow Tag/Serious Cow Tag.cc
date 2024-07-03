#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define BOUND 1001
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N;
int is_removed[BOUND];
pair<int, int> cows[BOUND];
/***********************/

void print_res() {
	for (int i = 0; i < N; i++) {
		if (!is_removed[i]) {
			cout << i + 1;
			exit(0);
		}
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> cows[i].X >> cows[i].Y;

	while (1) {
		if (count(is_removed, is_removed + N, 0) == 1)
			print_res();

		for (int i = 0; i < N; i++) {
			if (is_removed[i])
				continue;

			int min_dist = INT_MAX, min_idx = INT_MAX;

			for (int j = 0; j < N; j++) {
				if (j == i)
					continue;
				if (is_removed[j])
					continue;

				int dist = pow(cows[i].X - cows[j].X, 2) + pow(cows[i].Y - cows[j].Y, 2);

				if (min_dist > dist) {
					min_dist = dist;
					min_idx = j;
				}
			}

			if (min_idx == INT_MAX)
				print_res();
			else
				is_removed[min_idx] = 1;
		}
	}

	return 0;
}