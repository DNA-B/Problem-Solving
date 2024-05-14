#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/******** MACRO ********/
#define BOUND 300001
#define MAX 1'000'000'001
#define MOD 10000
#define ll long long
#define X first
#define Y second
/***********************/

using namespace std;

/****** VARIABLEs ******/
int N, K;
ll res = 0;
multiset<int> bag;
pair<int, int> jew[BOUND];
/***********************/

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> K;

	for (int m, v, i = 0; i < N; i++)
		cin >> jew[i].Y >> jew[i].X; // {가격, 무게}

	for (int c, i = 0; i < K; i++) {
		cin >> c;
		bag.insert(c);
	}

	sort(jew, jew + N, greater<pair<int, int>>()); // 가격 비싼순으로 정렬

	for (int i = 0; i < N; i++) {
		auto [v, m] = jew[i];
		auto it = bag.lower_bound(m); // (현재 보석의 무게 <= bag의 무게)인 배낭의 위치 찾기

		if (it == bag.end())
			continue;

		res += v;
		bag.erase(it);
	}

	cout << res;

	return 0;
}