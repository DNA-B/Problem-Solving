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
int N, M, res = 0;
int vis[100005], arr[100005];
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> M;


	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N);

	int lo = 0, hi = N - 1;
	while (lo < hi) {
		if (arr[lo] + arr[hi] < M)
			lo++;
		else {
			res++;
			lo++; hi--;
		}
	}

	cout << res;
	return 0;
}