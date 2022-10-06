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

long long sum_string(string str, long long* count)
{
	long long sum = 0;

	for (int i = 0; i < str.length(); i++)
	{
		sum += str[i] - '0';
	}

	str = to_string(sum);

	if (str.length() == 1)
	{
		(*count)++;
		return sum;
	}
	else
	{
		(*count)++;
		return sum_string(str, count);
	}

	
}

int main()
{
	string num;
	long long count = 0;
	long long result = 0;
	cin >> num;


	if (num.length() == 1)
	{
		if ((num[0] - '0') % 3 == 0)
		{
			cout << "0\nYES";
			return 0;
		}	
		else
		{
			cout << "0\nNO";
			return 0;
		}
	}

	result = sum_string(num, &count);

	if (result % 3 == 0)
	{
		cout << count << "\nYES";
	}
	else
	{
		cout << count << "\nNO";
	}

	return 0;
}