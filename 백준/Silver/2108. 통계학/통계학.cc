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

double mean(vector<int> &v) {
	double sum = 0;
	double mean_s;
	for (int i = 0; i < v.size(); i++)
	{
		sum += v[i];
	}
	mean_s = floor((sum / v.size()) + 0.5);
	return mean_s;
}

int middle(vector<int> &v)
{
	return v[v.size() / 2];
}

int freq(vector<int>& v, int arr[])
{
	int count = 1;
	int num = 0;
	int max = -1;

	for (int i = 0; i < v.size(); i++)
	{
		arr[v[i] + 4000]++;
	}

	for (int index : v)
	{
		if (index == num)
		{
			continue;
		}

		if (max <= arr[index + 4000])
		{
			if (max == arr[index + 4000])
			{
				if (count < 2)
				{
					count++;
					num = index;
				}
			}
			else
			{
				max = arr[index + 4000];
				num = index;
				count = 1;

			}
		}
	}
	return num;
}

int main()
{
	int num;
	int x;
	int n_freq[8001] = { 0 };
	vector<int> v;
	
	scanf("%d", &num);

	for (int i = 0; i < num; i++)
	{
		scanf("%d", &x);
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	
	printf("%.lf\n%d\n%d\n%d", mean(v), middle(v), freq(v, n_freq), v[v.size() - 1] - v[0]);
	return 0;
}