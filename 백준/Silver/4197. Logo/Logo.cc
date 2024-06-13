#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define BOUND 1001
#define MOD 1'000'000'007
#define PI 3.14159265358979323846
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int T, N;
/***********************/

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> T;

	while (T--) {
		double x = 0, y = 0;
		int num, angle = 0;
		string order;

		cin >> N;

		while (N--) {
			cin >> order >> num;

			if (order == "fd") {
				x += num * cos(angle * (PI / 180));
				y += num * sin(angle * (PI / 180));
			}
			else if (order == "bk") {
				x -= num * cos(angle * (PI / 180));
				y -= num * sin(angle * (PI / 180));
			}
			else if (order == "lt")
				angle += num;
			else if (order == "rt")
				angle -= num;
		}

		cout << fixed << setprecision(0) << sqrt(pow(x, 2) + pow(y, 2)) << "\n";
	}

	return 0;
}