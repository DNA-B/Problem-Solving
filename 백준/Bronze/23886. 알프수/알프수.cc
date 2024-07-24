#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define INF 0x3f3f3f3f
#define LLINF 1e18
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int I = -1;
int slope[100001];
string X;
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> X;

	if ((X[0] > X[1]) || (X[X.size() - 2] < X[X.size() - 1])) { // 처음이 내리막 혹은 마지막이 오르막이면 알프수 아님
		cout << "NON ALPSOO";
		exit(0);
	}

	for (int i = 0; i < X.size() - 1; i++) {
		slope[i] = X[i + 1] - X[i];

		if (slope[i] == 0) {
			cout << "NON ALPSOO";
			exit(0);
		}
	}

	for (int i = 1; i < X.size() - 1; i++) {
		if ((slope[i] > 0 && slope[i - 1] > 0) || (slope[i] < 0 && slope[i - 1] < 0)) {
			if (slope[i] != slope[i - 1]) {
				cout << "NON ALPSOO";
				exit(0);
			}
		}
	}

	cout << "ALPSOO";
	return 0;
}