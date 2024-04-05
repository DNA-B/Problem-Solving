#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> mem(100001, INT_MAX);

int solve(int cur) {
	for (int i = 1; i * i <= cur; i++) // min(mem[cur보다 작은 제곱수를 cur에서 뺀 값들])
		mem[cur] = min(mem[cur], mem[cur - (i * i)] + 1);

	return (cur == N) ? mem[N] : solve(cur + 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	mem[0] = 0;

	cin >> N;
	cout << solve(1);

	return 0;
}