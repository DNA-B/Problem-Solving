#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define BOUND 1005
#define MOD 1'000'000'007
#define PI 3.14159265358979323846
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int T, N;
double arr[BOUND], mem[BOUND];
/***********************/

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> T;

	while (T--) {
		fill(mem, mem + BOUND, 0);
		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> arr[i];
			mem[i] = arr[i];

			for (int j = 0; j < i - 2; j++)
				mem[i] = max(mem[i], arr[i] + mem[j]);
		}

		cout << fixed << setprecision(1);
		cout << *max_element(mem, mem + N) << "\n";
	}

	return 0;
}