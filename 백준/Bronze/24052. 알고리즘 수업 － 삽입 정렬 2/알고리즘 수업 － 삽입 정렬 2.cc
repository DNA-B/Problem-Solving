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
	int idx = 0;
	int ist;
	int count = 0;
	bool flag = 1;

	scanf("%d %d", &len, &k);

	for (int i = 0; i < len; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (int i = 1; i < len; i++)
	{
		idx = i - 1;
		ist = arr[i];

		while (idx >= 0 && ist < arr[idx])
		{
			arr[idx + 1] = arr[idx];
			idx--;
			count++;

			if (count == k)
			{
				flag = 0;
				break;
			}
		}

		if (flag == 0)
		{
			break;
		}

		if (idx + 1 != i)
		{
			arr[idx + 1] = ist;
			count++;

			if (count == k)
			{
				break;
			}
		}
	}

	if (count < k)
	{
		printf("-1");
	}
	else
	{
		for (int i = 0; i < len; i++)
		{
			printf("%d ", arr[i]);
		}
	}

	return 0;
}