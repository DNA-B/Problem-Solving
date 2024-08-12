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
string S;
int res = 0;
int arr[26] = {
	3, 2, 1, 2, 3, 3, 3, 3, 1, 1, 3, 1, 3,
	3, 1, 2, 2, 2, 1, 2, 1, 1, 2, 2, 2, 1
};
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
//	freopen("input.txt", "r", stdin);

	cin >> S;

	for (char ch : S)
		res += arr[ch - 'A'];

	cout << ((res & 1) ? "I'm a winner!" : "You're the winner?");
	return 0;
}