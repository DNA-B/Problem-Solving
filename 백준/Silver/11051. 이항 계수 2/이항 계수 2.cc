#define _CRT_SECURE_NO_WARNINGS
#define BOUND 1001
#define MOD 10007
#define first X
#define second Y

#include <bits/stdc++.h>

using namespace std;

int N, K;
int mem[BOUND][BOUND];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		mem[i][0] = mem[i][i] = 1;

		for (int j = 1; j < i; j++)
			mem[i][j] = (mem[i - 1][j] + mem[i - 1][j - 1]) % MOD;
	}

	cout << mem[N][K];

	return 0;
}