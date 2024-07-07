#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define BOUND 101
#define INF 0x3f3f3f3f
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int total = 0, x;
bool flag = true;
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	for (int i = 0; i < 10; i++) {
		cin >> x;

		if (!flag)
			continue;

		if (abs(100 - (total + x)) <= abs(100 - total))
			total += x;
		else // 한 번 안 먹으면 다음 버섯은 모두 못 먹음
			flag = false;
	}

	cout << total;
	return 0;
}