#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int main()
{
	int n;
	int m;
	int max = -1;
	int arr[100] = { 0 };

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n - 2; i++)
		for (int j = i + 1; j < n - 1; j++)
			for (int k = j + 1; k < n; k++)
				if (arr[i] + arr[j] + arr[k] <= m && arr[i] + arr[j] + arr[k] >= max)
					max = arr[i] + arr[j] + arr[k];

	cout << max;

	return 0;
}