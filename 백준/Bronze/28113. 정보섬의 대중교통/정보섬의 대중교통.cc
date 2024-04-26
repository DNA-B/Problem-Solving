#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/******** MACRO ********/
#define BOUND 2001
#define MAX 1'000'000'001
#define ll long long
#define X first
#define Y second
/***********************/

using namespace std;

/****** VARIABLEs ******/
int N, A, B;
/***********************/




int main() {
	cin.tie(0)->sync_with_stdio(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> A >> B;

	if (B > A) // 1 <= N <= B이므로 그냥 B와 A를 비교하는 것과 같다.
		cout << "Bus";
	else if (B < A)
		cout << "Subway";
	else
		cout << "Anything";

	return 0;
}