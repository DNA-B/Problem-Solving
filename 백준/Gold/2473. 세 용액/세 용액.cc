#define _CRT_SECURE_NO_WARNINGS
#define GOAL 100
#include <bits/stdc++.h>

using namespace std;

int N, M;
long long sol[5002];
long long ans = LLONG_MAX;
long long ans_sol[3];

int binary_search(long long n) { // auto casting하려고 long long 사용
	int st = 0, en = N - 1, mid;

	while (st <= en) {
		mid = (st + en) / 2;

		if (sol[mid] == n)
			return mid;
		else if (sol[mid] > n)
			en = mid - 1;
		else
			st = mid + 1;
	}

	if (st >= N) // 범위 넘어가면 검사 X
		return en;
	else if (en < 0)
		return st;

	return abs(sol[st] - n) > abs(sol[en] - n) ? en : st; // (st, en)으로 계산했을 때, 둘 중 0에 가까운 값 return 
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> sol[i];

	sort(sol, sol + N);

	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			int k = binary_search(-(sol[i] + sol[j])); // x+y+z = 0에 가까워야 함 -> z = -(x+y)
			long long cur = abs(sol[i] + sol[j] + sol[k]); // 0에 가까워야 하므로 절댓값으로 비교

			if (k < 0 || k >= N)
				continue;
			if (k == i || k == j)
				continue;

			if (ans > cur) {
				ans = cur;
				tie(ans_sol[0], ans_sol[1], ans_sol[2]) = { sol[i], sol[j], sol[k] };
			}
		}
	}

	sort(ans_sol, ans_sol + 3);
	cout << ans_sol[0] << " " << ans_sol[1] << " " << ans_sol[2];

	return 0;
}