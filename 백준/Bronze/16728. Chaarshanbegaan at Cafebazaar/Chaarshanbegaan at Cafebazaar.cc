#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
//========= MACRO =========//
#define PI 3.1415926535897932
#define INF 0x3f3f3f3f
#define LL_INF 1e18
#define ll long long
#define X first
#define Y second
//=========================//

//======= VARIABLEs =======//
int N, score = 0;
double x, y;
//=========================//

int solve(double d) {
	if (d <= 10) return 10;
	else if (d > 10 && d <= 30) return 9;
	else if (d > 30 && d <= 50) return 8;
	else if (d > 50 && d <= 70) return 7;
	else if (d > 70 && d <= 90) return 6;
	else if (d > 90 && d <= 110) return 5;
	else if (d > 110 && d <= 130) return 4;
	else if (d > 130 && d <= 150) return 3;
	else if (d > 150 && d <= 170) return 2;
	else if (d > 170 && d <= 190) return 1;
	else if (d > 190) return 0;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	while (N--) {
		cin >> x >> y;
		score += solve(sqrt((x * x) + (y * y)));
	}

	cout << score;
}