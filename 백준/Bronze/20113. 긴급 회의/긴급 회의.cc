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
int N, x, res = 0;
int vote[BOUND];
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> x;
		vote[x]++;
	}

	res = max_element(vote + 1, vote + (N + 1)) - vote;

	if (res == 0 || count(vote + 1, vote + (N + 1), vote[res]) > 1)
		cout << "skipped";
	else
		cout << res;

	return 0;
}