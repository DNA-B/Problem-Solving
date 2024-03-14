#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int N, M;
int x_1, y_1, x_2, y_2;
int arr[1025][1025];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> arr[i][j];
			arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
		}
	}

	for (int i = 0; i < M; i++)
	{
		cin >> x_1 >> y_1 >> x_2 >> y_2;
		cout << arr[x_2][y_2] - arr[x_1 - 1][y_2] - arr[x_2][y_1 - 1] + arr[x_1 - 1][y_1 - 1] << "\n";
	}

	return 0;
}