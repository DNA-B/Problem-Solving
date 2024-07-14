#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define BOUND 1000001
#define INF 0x3f3f3f3f
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N;
vector<int> v;
/***********************/

int gcd(int a, int b) {
	return (b == 0 ? a : gcd(b, a % b));
}

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;
	v.resize(N);

	for (int& num : v)
		cin >> num;

	int tmp = v[0];
	for (int i = 1; i < N; i++)
		tmp = gcd(tmp, v[i]);

	for (int i = 1; i <= tmp; i++) {
		if (tmp % i == 0)
			cout << i << "\n";
	}

	return 0;
}