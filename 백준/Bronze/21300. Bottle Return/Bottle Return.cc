#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int arr[6];
	int sum = 0;

	for (int i = 0; i < 6; i++)
	{
		cin >> arr[i];
		sum += arr[i] * 5;
	}

	cout << sum;
	return 0;
}