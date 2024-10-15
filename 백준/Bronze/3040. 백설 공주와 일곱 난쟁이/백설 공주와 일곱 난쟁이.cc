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
int sub, fake1, fake2;
int arr[10];
/***********************/

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		sub += arr[i];
	}

	sub -= 100; // 다 더한 값에서 100빼면 가짜 2명의 합
	sort(arr, arr + 9);

	for (int i = 0; i < 9; i++) {
		int idx = lower_bound(arr, arr + 9, sub - arr[i]) - arr; // sub에서 현재 위치빼면 나머지 가짜 1명의 값이고, lower_bound로 탐색

		if (idx != i && arr[i] + arr[idx] == sub) { // 나머지 가짜의 인덱스가 현재 위치인 i가 아니고 둘의 합이 sub라면 정답
			fake1 = i, fake2 = idx;
			break;
		}
	}

	for (int i = 0; i < 9; i++) {
		if (i != fake1 && i != fake2)
			cout << arr[i] << '\n';
	}

	return 0;
}