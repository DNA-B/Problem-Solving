#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define BOUND 200001
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N;
double x, y;
/***********************/

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> x >> y;
	cout << fixed << setprecision(8);

	while (N--) {
		int dist;
		string dir;

		cin >> dir >> dist;

		if (dir == "N")
			y += dist;
		else if (dir == "S")
			y -= dist;
		else if (dir == "E")
			x += dist;
		else if (dir == "W")
			x -= dist;
		else if (dir == "NE") {
			x += dist / sqrt(2);
			y += dist / sqrt(2);
		}
		else if (dir == "NW") {
			x -= dist / sqrt(2);
			y += dist / sqrt(2);
		}
		else if (dir == "SE") {
			x += dist / sqrt(2);
			y -= dist / sqrt(2);
		}
		else if (dir == "SW") {
			x -= dist / sqrt(2);
			y -= dist / sqrt(2);
		}
	}

	cout << x << " " << y;
	return 0;
}