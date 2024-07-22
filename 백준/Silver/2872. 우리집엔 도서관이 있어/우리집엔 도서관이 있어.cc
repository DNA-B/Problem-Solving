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
int N, book, cnt = 0;
int idx[300001];
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> book;
		idx[book] = i;
	}

	for (int i = N; i > 1; i--) {
		if (idx[i] > idx[i - 1])
			cnt++;
		else
			break;
	}

	cout << N - (cnt + 1); // 마지막 N번째 책은 무조건 안움직여도 되므로 +1
	return 0;
}