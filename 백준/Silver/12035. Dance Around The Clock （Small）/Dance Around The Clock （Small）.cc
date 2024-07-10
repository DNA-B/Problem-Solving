#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define BOUND 100001
#define INF 0x3f3f3f3f
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int T, D, K, N;
int arr[15];
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int turn = 0;
		cin >> D >> K >> N;

		for (int i = 0; i < D; i++)
			arr[i] = i + 1;

		while (turn++ < N) {
			if (turn & 1) { // 홀수 -> 시계 방향
				for (int i = 0; i < D - 1; i++) {
					swap(arr[i], arr[(i + 1) % D]);
					i++;
				}
			}
			else { // 짝수 -> 반시계 방향
				for (int i = 1; i < D; i++) {
					swap(arr[i], arr[(i + 1) % D]);
					i++;
				}
			}
		}

		int k_idx = find(arr, arr + D, K) - arr;
		cout << "Case #" << tc << ": " << arr[(k_idx + 1) % D] << " " << arr[((D + k_idx - 1) % D)] << "\n";
	}




	return 0;
}