#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

/******** MACRO ********/
#define INT_INF 0x3f3f3f3f
#define LL_INF 1e18
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N, M, res = 0;
int aarr[200005], barr[200005];
priority_queue<pair<int, int>> pq;
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> M;
	N *= 24;

	for (int i = 0; i < M; i++)
		cin >> aarr[i];
	for (int i = 0; i < M; i++)
		cin >> barr[i];
	for (int i = 0; i < M; i++)
		pq.push({ min(100 - aarr[i], barr[i]), i });

	while (N-- && !pq.empty()) {
		auto [val, idx] = pq.top(); pq.pop();
		aarr[idx] += val;
		if (aarr[idx] < 100)
			pq.push({ min(100 - aarr[idx], barr[idx]), idx });
	}

	for (int i = 0; i < M; i++)
		res += aarr[i];

	cout << res;
	return 0;
}