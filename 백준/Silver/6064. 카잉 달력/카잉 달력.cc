#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int T, M, N, x, y;

int gcd(int a, int b) {
	return (b == 0) ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}

int solve() {
	cin >> M >> N >> x >> y;

	int bound = lcm(M, N);

	for (int i = x; i <= bound; i += M) {
		int tmp = i % N; // x를 고정시키고 M을 계속해서 더한 값을 y'라고 했을 때 y' % N이 y라면 <x, y>의 해는 i이다

		if (tmp == 0) // 카잉 달력은 M, N까지 갔다가 1로 돌아감
			tmp = N;

		if (tmp == y)
			return i;
	}

	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> T;

	while (T--)
		cout << solve() << '\n';

	return 0;
}