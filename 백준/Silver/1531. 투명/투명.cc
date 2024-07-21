#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define BOUND 101
#define INF 0x3f3f3f3f
#define LLINF 1e18
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N, M, cnt = 0;
int X1, X2, Y1, Y2;
int arr[BOUND][BOUND];
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> X1 >> Y1 >> X2 >> Y2;

		for (int j = X1; j <= X2; j++) {
			for (int k = Y1; k <= Y2; k++)
				arr[j][k]++;
		}
	}

	for (int i = 1; i < BOUND; i++) {
		for (int j = 1; j < BOUND; j++) {
			if (arr[i][j] > M)
				cnt++;
		}
	}

	cout << cnt;
	return 0;
}