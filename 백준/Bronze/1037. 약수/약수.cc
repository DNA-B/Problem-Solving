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
	int n;
	int real[50] = { 0 };
	int max = -1;
	int min = 1000001;
	int result = 0;
	

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> real[i];

		if (real[i] > max)
		{
			max = real[i];
		}

		if (real[i] < min)
		{
			min = real[i];
		}
	}

	cout << max * min;

	return 0;
}