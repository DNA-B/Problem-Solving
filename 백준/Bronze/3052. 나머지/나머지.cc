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
	int count[42] = { 0 };
	int arr[10] = { 0 };
	int result = 0;

	for (int i = 0; i < 10; i++)
	{
		cin >> arr[i];
		count[arr[i] % 42]++;
	}

	for (int i = 0; i < 42; i++)
	{
		if (count[i] != 0)
		{
			result++;
		}
	}

	cout << result;

	return 0;
}