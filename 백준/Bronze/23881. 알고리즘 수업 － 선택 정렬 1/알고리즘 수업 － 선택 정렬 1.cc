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
	int len;
	int k;
	int arr[10000] = { 0 };
	int max = -1;
	int count = 0;
	int max_idx;
	int maxi, mini;

	int i, j;

	scanf("%d %d", &len, &k);

	for (int i = 0; i < len; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (i = len - 1; i > 0; i--)
	{
		for (j = 0; j <= i; j++)
		{
			if (arr[j] > max)
			{
				max = arr[j];
				max_idx = j;
			}
		}

		if (i != max_idx)
		{
			swap(arr[i], arr[max_idx]);
			count++;

			if (count == k)
			{
				mini = arr[max_idx];
				maxi = arr[i];
				break;
			}
		}
		max = -1;
	}

	if (count < k)
	{
		printf("-1");
	}
	else
	{
		printf("%d %d", mini, maxi);
	}

	return 0;
}