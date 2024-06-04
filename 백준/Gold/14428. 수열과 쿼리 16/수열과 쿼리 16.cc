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
const int MX_N = 100004;
const int INVALID = -1;
int N, M;
int seg[4 * MX_N];
int arr[MX_N];
/***********************/

int seg_func(int a, int b) { 
	if (a == INVALID)
		return b;
	if (b == INVALID)
		return a;

	return arr[a] <= arr[b] ? a : b;
}

int seg_update(int i, int val, int node, int st, int en) {
	if (st > i || i > en)
		return seg[node];
	if (st == en)
		return seg[node] = i;

	int mid = (st + en) / 2;

	return seg[node] = seg_func(seg_update(i, val, node * 2, st, mid), seg_update(i, val, node * 2 + 1, mid + 1, en));
}

int seg_query(int a, int b, int node, int st, int en) {
	if (en < a || b < st)
		return INVALID;
	if (a <= st && en <= b)
		return seg[node];

	int mid = (st + en) / 2;

	return seg_func(seg_query(a, b, node * 2, st, mid), seg_query(a, b, node * 2 + 1, mid + 1, en));
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 1; i < N + 1; i++) {
		cin >> arr[i];
		seg_update(i, arr[i], 1, 1, N);
	}

	cin >> M;

	while (M--) {
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 1) {
			arr[b] = c;
			seg_update(b, c, 1, 1, N);
		}
		else
			cout << seg_query(b, c, 1, 1, N) << "\n";
	}

	return 0;
}