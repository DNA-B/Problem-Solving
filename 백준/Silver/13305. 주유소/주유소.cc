#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/******** MACRO ********/
#define BOUND 100'001
#define MAX 1'000'000'001
#define MOD 10000
#define ll long long
#define X first
#define Y second
/***********************/

using namespace std;

/****** VARIABLEs ******/
int N;
ll res = LLONG_MAX, cur_dist = 0;
ll city[BOUND], dist[BOUND], cost[BOUND];
/***********************/

int main() {
	cin.tie(0)->sync_with_stdio(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 1; i <= N - 1; i++) {
		cin >> dist[i];
		cur_dist += dist[i]; // 현재까지의 길이
	}

	for (int i = 1; i <= N; i++) {
		cin >> city[i];
		cost[i] = cost[i - 1] + (city[i] * dist[i]); // 이전 도시에서의 cost + (i번째 도시 기름 값 * 거리)
	}

	for (int i = 1; i <= N - 1; i++) {
		ll cur_cost = cost[i - 1] + (city[i] * cur_dist); // 이전 cost + (현재 도시 기름값 * 남은 거리)

		res = min(res, cur_cost);
		cur_dist -= dist[i]; // 남은 길이 갱신
	}

	cout << res;

	return 0;
}