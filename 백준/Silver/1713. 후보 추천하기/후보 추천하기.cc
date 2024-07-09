#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define BOUND 101
#define INF 0x3f3f3f3f
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N, M;
int rec[BOUND], post[BOUND];
/***********************/

int get_min_post(int min_idx) { // 가장 게시가 오래된 사진은 i가 작은 값이므로 min
	int min_post = INT_MAX, min_post_idx = INT_MAX;

	for (int i = 1; i <= BOUND - 1; i++) {
		if (rec[i] == rec[min_idx]) {
			if (min_post > post[i]) {
				min_post = post[i];
				min_post_idx = i;
			}
		}
	}

	return min_post_idx;
}

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> M;

	fill(rec, rec + BOUND, INT_MAX);
	fill(post, post + BOUND, INT_MAX);

	for (int x, i = 0; i < M; i++) {
		cin >> x;

		if (rec[x] != INT_MAX) {
			rec[x]++;
			continue;
		}

		if ((BOUND - 1) - count(post + 1, post + BOUND, INT_MAX) == N) { // 사진틀 꽉참
			int min_idx = min_element(rec + 1, rec + BOUND) - rec;
			int min_post_idx = get_min_post(min_idx);
			post[min_post_idx] = rec[min_post_idx] = INT_MAX;
		}

		post[x] = i;
		rec[x] = 1;
	}

	for (int i = 1; i <= BOUND - 1; i++) {
		if (rec[i] != INT_MAX)
			cout << i << " ";
	}

	return 0;
}