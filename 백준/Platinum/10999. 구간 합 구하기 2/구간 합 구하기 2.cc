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
ll N, M, K, cnt;
ll a, b, c, d;
/***********************/

struct Segment {
	vector<ll> tree;
	vector<ll> seq;
	vector<ll> lazy;

	Segment(ll n) {
		seq.resize(n + 1);
		ll log = ceil(log2(n));
		ll t = (1LL << (log + 1));
		tree.resize(t);
		lazy.resize(t);
	}

	void init(ll node, ll start, ll end) {
		ll mid = (start + end) / 2;

		if (start == end)
			tree[node] = seq[start];
		else {
			init(node * 2, start, mid);
			init(node * 2 + 1, mid + 1, end);
			tree[node] = tree[node * 2] + tree[node * 2 + 1];
		}
	}

	ll query(ll node, ll start, ll end, ll i, ll j) {
		ll mid = (start + end) / 2;

		if (lazy[node] != 0) {
			tree[node] += (end - start + 1) * lazy[node];
			if (start != end) {
				lazy[node * 2] += lazy[node];
				lazy[node * 2 + 1] += lazy[node];
			}
			lazy[node] = 0;
		}
		if (i > end || j < start)
			return 0;
		if (i <= start && end <= j)
			return tree[node];

		return query(node * 2, start, mid, i, j) + query(node * 2 + 1, mid + 1, end, i, j);
	}

	void update(ll node, ll start, ll end, ll i, ll j, ll diff) {
		ll mid = (start + end) / 2;

		if (lazy[node] != 0) {
			tree[node] += (end - start + 1) * lazy[node];
			if (start != end) {
				lazy[node * 2] += lazy[node];
				lazy[node * 2 + 1] += lazy[node];
			}
			lazy[node] = 0;
		}
		if (j < start || i > end)
			return;
		if (i <= start && end <= j) {
			tree[node] += (end - start + 1) * diff;
			if (start != end) {
				lazy[node * 2] += diff;
				lazy[node * 2 + 1] += diff;
			}
			return;
		}

		update(node * 2, start, mid, i, j, diff);
		update(node * 2 + 1, mid + 1, end, i, j, diff);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
};

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> M >> K;

	Segment se(N);

	for (int i = 1; i <= N; i++)
		cin >> se.seq[i];

	se.init(1, 1, N);
	cnt = M + K;

	while (cnt--) {
		cin >> a;

		if (a == 1) {
			cin >> b >> c >> d;
			se.update(1, 1, N, b, c, d);
		}
		else {
			cin >> b >> c;
			cout << se.query(1, 1, N, b, c) << "\n";
		}
	}

	return 0;
}