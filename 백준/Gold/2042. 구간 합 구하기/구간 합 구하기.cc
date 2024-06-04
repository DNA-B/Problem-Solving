#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/******** MACRO ********/
#define BOUND 10
#define MOD 1'000
#define ll long long
#define X first
#define Y second
/***********************/

using namespace std;

/****** VARIABLEs ******/
ll N, M, K, a, b, c;
vector<ll>A(1000007);
vector<ll>Tree(1000007);
/***********************/


ll sum(ll i) {
	ll ans = 0;

	while (i > 0) {
		ans += Tree[i];
		i -= (i & -i);
	}

	return ans;
}

void update(ll i, ll num) {
	while (i <= N) {
		Tree[i] += num;
		i += (i & -i);
	}
}


int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		update(i, A[i]);
	}

	for (int i = 0; i < M + K; i++) {
		cin >> a >> b >> c;

		if (a == 1) {
			ll diff = c - A[b];
			A[b] = c;
			update(b, diff);
		}
		else
			cout << sum(c) - sum(b - 1) << "\n";
	}

	return 0;
}