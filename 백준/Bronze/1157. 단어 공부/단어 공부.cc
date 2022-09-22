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
	int max = -1;
	int index = -1;
	int arr[26] = { 0 };
	string str;

	cin >> str;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= 65 && str[i] <= 90)
		{
			arr[str[i] - 65]++;
		}
		else if (str[i] >= 97 && str[i] <= 122)
		{
			arr[str[i] - 97]++;
		}
	}

	for (int i = 0; i < 26; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			index = i;
		}
	}

	if (count(arr, arr + 26, max) == 1)
	{
		cout << (char)(index + 65);
	}
	else
	{
		cout << '?';
	}

	return 0;
}