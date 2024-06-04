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
const int MX_N = 2e6;
const int INVALID = -1;
int N, M;
int arr[MX_N];
int seg[MX_N * 4 + 6];
/***********************/

int query(int node, int s, int e, int k) {
	seg[node]--;

	if (s == e)
		return s;

	int mid = (s + e) >> 1;

	if (seg[2 * node] >= k)
		return query(2 * node, s, mid, k);

	else return query(2 * node + 1, mid + 1, e, k - seg[2 * node]);
}


void update(int node, int s, int e, int idx) {
	if (idx < s || e < idx)
		return;

	seg[node]++;

	if (s == e)
		return;

	int mid = (s + e) >> 1;

	update(2 * node, s, mid, idx);
	update(2 * node + 1, mid + 1, e, idx);
}


int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	while (N--) {
		int s, x;
		cin >> s >> x;

		if (s == 1)
			update(1, 1, MX_N, x);
		else
			printf("%d\n", query(1, 1, MX_N, x));
	}

	return 0;
}