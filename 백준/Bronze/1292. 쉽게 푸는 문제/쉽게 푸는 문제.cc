#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

//
int main()
{
	int n1;
	int n2;
	int sum = 0;
	int num = 1;
	int count = 1;
	int i = 1;

	cin >> n1 >> n2;

	while (i <= n2)
	{
		if (i >= n1 && i <= n2)
		{
			sum += num;
		}

		if (count == num)
		{
			count = 1;
			num++;
			i++;
			continue;
		}

		count++;
		i++;
	}

	cout << sum;
	return 0;
}