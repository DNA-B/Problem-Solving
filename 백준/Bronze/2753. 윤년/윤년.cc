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
	int year = 0;

	cin >> year;

	if (year % 4 == 0)
	{
		if (year % 400 == 0)
		{
			cout << 1;
		}
		else if (year % 100 != 0)
		{
			cout << 1;
		}
		else
		{
			cout << 0;
		}
	}
	else
	{
		cout << 0;
	}

	return 0;

}