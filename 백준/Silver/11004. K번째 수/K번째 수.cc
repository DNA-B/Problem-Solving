#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int N, K;
int arr[5000001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> K;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N);
	cout << arr[K - 1];

	return 0;
}