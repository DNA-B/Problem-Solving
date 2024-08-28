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
string A, B; // 가로, 세로
int a_idx = -1, b_idx = -1;
/***********************/

void find_idx() {
	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < B.size(); j++) {
			if (A[i] == B[j]) {
				a_idx = i;
				b_idx = j;
				return;
			}
		}
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> A >> B;

	find_idx();

	for (int i = 0; i < B.size(); i++) { // row
		for (int j = 0; j < A.size(); j++) { // col
			if (i == b_idx && j == a_idx)
				cout << B[i];
			else if (i == b_idx)
				cout << A[j];
			else if (j == a_idx)
				cout << B[i];
			else
				cout << '.';
		}
		cout << '\n';
	}

	return 0;
}