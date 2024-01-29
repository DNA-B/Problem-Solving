#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int N, ans = 0;
int A[301][301], B[301][301], C[301][301];

void make_c(int x, int y)
{
	for (int i = 0; i < N; i++)
		C[x][y] |= A[x][i] & B[i][y];

	if (C[x][y] == 1)
		ans++;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> A[i][j];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> B[i][j];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			make_c(i, j);

	cout << ans;

	return 0;
}