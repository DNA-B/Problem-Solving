#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

int N, M;
long long mem[1001][1001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	mem[1][1] = 1;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (i - 1 < 1 && j - 1 > 0) // row가 범위를 벗어난 경우
				mem[i][j] = mem[i][j - 1] % MOD;
			else if (i - 1 > 0 && j - 1 < 1) // col이 범위를 벗어난 경우
				mem[i][j] = mem[i - 1][j] % MOD;
			else if (i - 1 > 0 && j - 1 > 0) // 모두 범위 내
				mem[i][j] = (mem[i - 1][j] + mem[i][j - 1] + mem[i - 1][j - 1]) % MOD;
		}
	}

	cout << mem[N][M];

	return 0;
}