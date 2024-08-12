#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

/******** MACRO ********/
#define INT_INF 0x3f3f3f3f
#define LL_INF 1e18
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N, M, res = INT_MAX;
int arr[101][3];
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				int cnt = 0;

				for (int jinsu = 0; jinsu < N; jinsu++) {
					if ((arr[i][0] >= arr[jinsu][0]) &&
						(arr[j][1] >= arr[jinsu][1]) &&
						(arr[k][2] >= arr[jinsu][2]))
						cnt++;
				}

				if (cnt >= M)
					res = min({ res, arr[i][0] + arr[j][1] + arr[k][2] });
			}
		}
	}

	cout << res;
	return 0;
}