#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

/******** MACRO ********/
#define PI 3.1415926535897932
#define MOD 1000000007
#define INT_INF 0x3f3f3f3f
#define LL_INF 1e18
#define ll long long
#define ull usnsigned long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N, S;
int arr[45];
ll cnt = 0;
unordered_map<int, int> um;
/***********************/

void l_dfs(int cur, int total) {
	if (cur == N / 2) {
		um[total]++;
		return;
	}

	l_dfs(cur + 1, total + arr[cur]);
	l_dfs(cur + 1, total);
}

void r_dfs(int cur, int total) {
	if (cur == N) {
		cnt += um[S - total];
		return;
	}

	r_dfs(cur + 1, total + arr[cur]);
	r_dfs(cur + 1, total);
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> S;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	l_dfs(0, 0);
	r_dfs(N / 2, 0);

	cout << (S == 0 ? cnt - 1 : cnt);
	return 0;
}