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
	int hour;
	int minute;

	cin >> hour;
	cin >> minute;

	minute -= 45;

	if (minute < 0)
	{
		if (hour == 0)
		{
			hour = 23;
			minute += 60;
		}
		else
		{
			hour -= 1;
			minute += 60;
		}
	}

	cout << hour << ' ' << minute;

	return 0;
}