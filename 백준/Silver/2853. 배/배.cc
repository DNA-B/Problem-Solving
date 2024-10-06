#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_set>
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
int N, cnt = 0;
int day[5005];
/***********************/

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> day[i];

	for (int i = 1; i < N; i++) {
		if (!day[i]) continue;
		int diff = day[i] - 1; // 첫 날은 무조건 1
		bool flag = false;
		for (int j = 1; j < N; j++) {
			if (!day[j]) continue;
			if (day[j] % diff == 1) { // a + (n-1)d
				flag = true;
				day[j] = 0;
			}
		}
		if (flag) cnt++;
	}

	cout << cnt;
	return 0;
}