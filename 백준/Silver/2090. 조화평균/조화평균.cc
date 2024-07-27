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
ll N, tmp, LCM, mo, ja;
int arr[10];
/***********************/

ll gcd(ll a, ll b) {
	return (b == 0 ? a : gcd(b, a % b));
}

ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	mo = arr[0];
	for (int i = 1; i < N; i++)
		mo = lcm(mo, arr[i]);
	for (int i = 0; i < N; i++)
		ja += mo / arr[i];

	cout << mo / gcd(mo, ja) << '/' << ja / gcd(mo, ja);
	return 0;
}