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
	string str1;
	string str2;

	cin >> str1 >> str2;

	if (str1[2] - '0' > str2[2] - '0')
	{
		cout << str1[2] << str1[1] << str1[0];
	}
	else if (str1[2] - '0' < str2[2] - '0')
	{
		cout << str2[2] << str2[1] << str2[0];
	}
	else
	{
		if (str1[1] - '0' > str2[1] - '0')
		{
			cout << str1[2] << str1[1] << str1[0];
		}
		else if (str1[1] - '0' < str2[1] - '0')
		{
			cout << str2[2] << str2[1] << str2[0];
		}
		else
		{
			if (str1[0] - '0' > str2[0] - '0')
			{
				cout << str1[2] << str1[1] << str1[0];
			}
			else if (str1[0] - '0' < str2[0] - '0')
			{
				cout << str2[2] << str2[1] << str2[0];
			}
		}
	}

	return 0;
}