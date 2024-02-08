#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int H, W, X, Y;
int A[302][302], B[602][602];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> H >> W >> X >> Y;

	for (int i = 0; i < H + X; i++)
		for (int j = 0; j < W + Y; j++)
			cin >> B[i][j];

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if ((i - X) >= 0 && (j - Y) >= 0)
				A[i][j] = B[i][j] - A[i - X][j - Y];
			else
				A[i][j] = B[i][j];
		}
	}

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
			cout << A[i][j] << " ";
		cout << "\n";
	}

	return 0;
}