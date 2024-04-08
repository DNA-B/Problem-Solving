#define _CRT_SECURE_NO_WARNINGS
#define BOUND 4000000
#include <bits/stdc++.h>

using namespace std;

int N;
int ans = 0;
int p_sum[BOUND + 1];
vector<bool> is_prime(BOUND + 1, true);
vector<int> prime;

void era(int n) {
	is_prime[0] = is_prime[1] = false;

	for (int i = 2; i * i <= n; i++) {
		if (!is_prime[i])
			continue;

		for (int j = i * i; j <= n; j += i)
			is_prime[j] = false;
	}

	for (int i = 2; i <= n; i++) {
		if (is_prime[i])
			prime.push_back(i);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;

	prime.push_back(0); // 인덱스 1번 기준으로 계산하기 위해서 더미 값 0 push
	era(N);

	for (int i = 1; i < prime.size(); i++)
		p_sum[i] = p_sum[i - 1] + prime[i];

	for (int st = 0, en = 1; st < prime.size(); st++) {
		while (en < prime.size() && (p_sum[en] - p_sum[st]) < N)
			en++;

		if (en == prime.size())
			break;

		if (p_sum[en] - p_sum[st] == N) // p_sum[en] - p_sum[st] => st + 1부터 en까지의 합
			ans++;
	}

	cout << ans;

	return 0;
}