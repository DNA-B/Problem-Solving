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
int N;
vector<int> v;
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;
	v.resize(N);

	for (auto& n : v)
		cin >> n;

	if (is_sorted(v.begin(), v.end())) {
		cout << -1;
		exit(0);
	}

	prev_permutation(v.begin(), v.end());

	for (auto n : v)
		cout << n << " ";

	return 0;
}