#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define BOUND 300001
#define INF 0x3f3f3f3f
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N, x;
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> x;

		if ((x & 1) && (i & 1)) { // 홀 -> 짝
			cout << "NO";
			exit(0);
		}
		else if (!(x & 1) && !(i & 1)) { // 짝 -> 홀
			cout << "NO";
			exit(0);
		}
	}

	cout << "YES";
	return 0;
}