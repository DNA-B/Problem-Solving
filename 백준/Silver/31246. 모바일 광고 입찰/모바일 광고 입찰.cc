#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define BOUND 100001
#define INF 0x3f3f3f3f
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N, K;
vector<int> sub;
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> K;

	for (int a, b, i = 0; i < N; i++) {
		cin >> a >> b;
		a >= b ? sub.push_back(0) : sub.push_back(b - a);
	}

	sort(sub.begin(), sub.end());
	cout << sub[K - 1];

	return 0;
}