#define _CRT_SECURE_NO_WARNINGS

#include <iostream> // C++ library
#include <algorithm>
#include <string>
#include <cctype> // C library
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector> // STL
#include <queue>
#include <stack>
#include <list>

using namespace std;

int b_search(vector<int>& v, int target)
{
	int start = 0;
	int end = v.size() - 1;
	int mid = (start + end) / 2;

	while (start <= end)
	{
		if (v[mid] == target)
		{
			return 1;
		}
		else if (v[mid] <= target)
		{
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
		mid = (end + start) / 2;
	}

	return 0;
}

int main()
{
	vector<int> v;
	vector<int> target;
	int num;
	int target_num;
	int x;

	scanf("%d", &num);

	for (int i = 0; i < num; i++)
	{
		scanf("%d", &x);
		v.push_back(x);
	}
	sort(v.begin(), v.end());


	scanf("%d", &target_num);
	for (int i = 0; i < target_num; i++)
	{
		scanf("%d", &x);
		target.push_back(x);
	}

	for (int i = 0; i < target_num; i++)
	{
		printf("%d\n", b_search(v, target[i]));
	}
	
	return 0;
}