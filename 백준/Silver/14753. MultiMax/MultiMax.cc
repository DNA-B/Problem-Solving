#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int N;
int arr[10001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N);

	int tmp1 = arr[N - 1] * arr[N - 2]; // 양 * 양
	int tmp2 = tmp1 * arr[N - 3]; // 양 * 양 * 양
	int tmp3 = arr[0] * arr[1]; // 음 * 음
	int tmp4 = tmp3 * arr[N - 1]; // 음 * 음 * 양

	cout << max({ tmp1, tmp2, tmp3, tmp4 });

	return 0;
}