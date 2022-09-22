#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

// 2750번 : 수 정렬하기
// 선택 정렬
int main()
{
	int arr[1000] = { 0 };
	int mini = 0;
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < n - 1; i++)
	{
		mini = i;

		for (int j = i; j < n; j++)
		{
			if (arr[j] < arr[mini])
			{
				mini = j;
			}
		}

		if (i == mini)
		{
			continue;
		}

		swap(arr[i], arr[mini]);
	}

	for (int i = 0; i < n; i++)
	{
		printf("%d\n", arr[i]);
	}

	return 0;
}