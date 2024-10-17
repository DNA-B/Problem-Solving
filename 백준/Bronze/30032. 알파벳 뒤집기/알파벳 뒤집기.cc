#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define PI 3.1415926535897932
#define MOD 1000000007
#define INT_INF 0x3f3f3f3f
#define LL_INF 1e18
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N, D;
char alp;
/***********************/

char up_down(char& ch) {
	if (ch == 'd')
		return 'q';
	else if (ch == 'b')
		return 'p';
	else if (ch == 'q')
		return 'd';
	else if (ch == 'p')
		return 'b';
}

char left_right(char& ch) {
	if (ch == 'd')
		return 'b';
	else if (ch == 'b')
		return 'd';
	else if (ch == 'q')
		return 'p';
	else if (ch == 'p')
		return 'q';
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> D;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> alp;
			cout << (D == 1 ? up_down(alp) : left_right(alp));
		}
		cout << '\n';
	}

	return 0;
}