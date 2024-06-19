#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define BOUND 21
#define MOD 1'000'000'007
#define PI 3.14159265358979323846
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int T, R;
string jenga;
/***********************/

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> T;

	for (int i = 1; i <= T; i++) {
		bool is_fallen = false;

		cin >> R;

		while (R--) {
			cin >> jenga;

			if (jenga.find("00") != -1) // 연속된 두 개의 제거된 블록을 찾아야 함
				is_fallen = true;
		}

		cout << "Case " << i << ": " << (is_fallen ? "Fallen" : "Standing") << "\n";
	}

	return 0;
}