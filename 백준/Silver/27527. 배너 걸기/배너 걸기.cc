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
int N, M, bound;
int arr[200005];
unordered_map<int, int> um;
/***********************/

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> M;
	bound = ceil((9 * M) / 10.0);

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 0; i < M; i++) {
		um[arr[i]]++;

		if (um[arr[i]] >= bound) {
			cout << "YES";
			exit(0);
		}
	}

	for (int i = M; i < N; i++) {
		um[arr[i - M]]--;
		um[arr[i]]++;

		if (um[arr[i]] >= bound) {
			cout << "YES";
			exit(0);
		}
	}

	cout << "NO";
	return 0;
}