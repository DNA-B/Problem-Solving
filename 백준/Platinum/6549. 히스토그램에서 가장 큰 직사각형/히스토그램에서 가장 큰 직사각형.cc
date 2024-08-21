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
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N, K;
ll arr[100005];
/***********************/

ll solve(ll st, ll en) {
	ll mid = (st + en) / 2;
	ll mn = arr[mid], h = arr[mid];
	ll l = mid - 1, r = mid + 1;

	if (st + 1 >= en)
		return mn;

	while (st < l || r < en) {
		if (st >= l || (r < en && arr[l] <= arr[r])) {
			h = min(h, arr[r]);
			r++;
		}
		else {
			h = min(h, arr[l]);
			l--;
		}
		mn = max(mn, ((r - l) - 1) * h);
	}

	return max(mn, max(solve(st, mid), solve(mid, en)));
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	while (1) {
		cin >> N;
		if (!N) break;
		for (int i = 1; i <= N; i++) cin >> arr[i];
		cout << solve(0, N + 1) << "\n";
	}

	return 0;
}