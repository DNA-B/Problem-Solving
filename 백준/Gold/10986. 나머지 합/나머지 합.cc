#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/******** MACRO ********/
#define BOUND 1'000'001
#define MAX 1'000'000'001
#define MOD 10000
#define ll long long
#define X first
#define Y second
/***********************/

using namespace std;

/****** VARIABLEs ******/
int N, M;
ll res = 0;
int arr[BOUND];
int mod_sum[BOUND];
map<int, int> mod_cnt;
/***********************/

int main() {
	cin.tie(0)->sync_with_stdio(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		mod_sum[i] = (mod_sum[i - 1] + arr[i]) % M; // 최대 1e9 + 999 이므로 int overflow 괜찮다.

		if (mod_sum[i] == 0) // 1번칸부터 i까지의 합이 0일 때
			res++;

		res += mod_cnt[mod_sum[i]]; // mod_sum[i]랑 mod_sum[x]가 값이 같다면 x ~ i까지의 합은 M으로 나눠진다.
		mod_cnt[mod_sum[i]]++;
	}

	cout << res;

	return 0;
}