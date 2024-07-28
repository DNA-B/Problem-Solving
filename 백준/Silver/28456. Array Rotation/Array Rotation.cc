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
int N, Q, order;
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;
	deque<deque<int>> dq(N, deque<int>(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> dq[i][j];
		}
	}

	cin >> Q;

	while (Q--) {
		cin >> order;

		if (order == 1) {
			int x;
			cin >> x;
			dq[x - 1].push_front(dq[x - 1].back());
			dq[x - 1].pop_back();
		}
		else if (order == 2) {
			deque<deque<int>> tmp(N, deque<int>(N));
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++)
					tmp[j][N - (i + 1)] = dq[i][j];
			}
			dq = tmp;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << dq[i][j] << " ";
		cout << "\n";
	}

	return 0;
}