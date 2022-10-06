#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int max = -1000001;
	int min = 1000001;
	int len;
	int num;

	cin >> len;

	for (int i = 0; i < len; i++)
	{
		cin >>num;
		
		if (num > max)
		{
			max = num;
		}

		if (num < min)
		{
			min = num;
		}
	}

	cout << min << ' ' << max;

	return 0;
}