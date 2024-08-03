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
int N, L, R, X, res = 0;
int diff[20], vis[20], arr[20];
/***********************/

void solve(int cnt, int idx) {
	if (cnt > N)
		return;
	if (cnt >= 2 && arr[cnt - 1] - arr[0] >= X) {
		ll total = accumulate(arr, arr + cnt, 0LL);

		if (L <= total && total <= R)
			res++;
		else if (total > R) // total이 R보다 크면 뒤에 어떤 수를 추가해도 R보다 큼
			return;
	}

	for (int i = idx; i < N; i++) {
		if (!vis[i]) {
			vis[i] = 1;
			arr[cnt] = diff[i];
			solve(cnt + 1, i + 1);
			vis[i] = 0;
		}
	}
}

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> L >> R >> X;

	for (int i = 0; i < N; i++)
		cin >> diff[i];

	sort(diff, diff + N);
	solve(0, 0);

	cout << res;
	return 0;
}