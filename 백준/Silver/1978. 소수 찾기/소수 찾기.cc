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

bool prime_num[1001];

void eratos(bool arr[])
{
	arr[1] = false;

	for (int i = 2; (i * i) < 1001; i++)
	{
		if (arr[i])
		{
			for (int j = (i * i); j < 1001; j += i)
			{
				arr[j] = false;
			}
		}
	}
}

int main()
{
	memset(prime_num, true, 1001);

	vector<int> v;
	int x = 0;
	int n = 0;
	int count = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		v.push_back(x);
	}

	eratos(prime_num);

	for (int i = 0; i < n; i++)
	{
		if (prime_num[v.at(i)])
		{
			count++;
		}
	}
	
	printf("%d", count);
	return 0;
}