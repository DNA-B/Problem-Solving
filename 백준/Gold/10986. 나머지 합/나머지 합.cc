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
ll res = 0;
int N, M;
int arr[BOUND];
map<int, int> mod_cnt;
/***********************/

int main() {
	cin.tie(0)->sync_with_stdio(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M;

	for (int x, i = 1; i <= N; i++) {
		cin >> x;
		arr[i] = (arr[i - 1] + x) % M; // 최대 (1e9 + (M - 1)) 이므로 int overflow 괜찮다.

		if (arr[i] == 0)
			res++;

		res += mod_cnt[arr[i]]; // 내 앞에 나와 값이 같은 곳이 있다면 구간 형성이 가능 (ex : 내 앞이 1 0 0이고 내가 1이면 1 ~ cur)
		mod_cnt[arr[i]]++;
	}

	cout << res; // 만약 N이 10^6이고 모든 값이 M의 배수라면 mod_cnt[0]이 계속 증가하고 res는 0 ~ (10^6 - 1)의 합이 되므로 overflow 발생

	return 0;
}