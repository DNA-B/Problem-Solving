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
int N, tmp = 0;
int arr[1001];
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		tmp += (i & 1 ? -arr[i] : arr[i]); // n이 3일 때, x+y | y+z | z+x라면 첫 항 x를 구하기 위해 홀수는 빼고 짝수는 더한다.
	}

	tmp /= 2; // 위 식의 결과가 (2 * 첫 항) 이므로 나누기 2
	cout << tmp << "\n";

	for (int i = 0; i < N - 1; i++) {
		arr[i] -= tmp;
		tmp = arr[i]; // x+y였다면 y를 구했고, y+z에서 z를 구하기 위해 tmp를 y로 갱신
		cout << arr[i] << "\n";
	}

	return 0;
}