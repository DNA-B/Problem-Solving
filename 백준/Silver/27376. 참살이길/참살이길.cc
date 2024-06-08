#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/******** MACRO ********/
#define BOUND 100001
#define MOD 1'000'000'007
#define ll long long
#define X first
#define Y second
/***********************/

using namespace std;

/****** VARIABLEs ******/
int N, K;
ll res = 0, is_green;
tuple<int, int, int> light[BOUND]; // [x, s, t]
/***********************/

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> K;

	for (int i = 1; i <= K; i++) {
		int x, t, s;
        
		cin >> x >> t >> s;
		light[i] = { x, t, s };
	}

	sort(light + 1, light + (K + 1)); // 좌표순 정렬

	for (int i = 1; i <= K; i++) {
		auto [x, t, s] = light[i];

	    res += x - get<0>(light[i - 1]); // 현재 거리 - 이전 거리
		is_green = (res - s) % (2 * t);

		if (is_green < 0) // s > res인 경우
			res += s - res;
		else if (t <= is_green && is_green < 2 * t) // 신호등이 빨간불인 경우
			res += (2 * t) - is_green;
	}

	res += N - get<0>(light[K]); // 목적지 - 마지막 신호등 거리
	cout << res;

	return 0;
}