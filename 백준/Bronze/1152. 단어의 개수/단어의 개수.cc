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
	string str;
	int result = 0;

	getline(cin, str);

	if (str == " ")
	{
		cout << 0;
		return 0;
	}

	for (int i = 0; i < str.size(); i++)
	{
		if (i != 0 && i != str.size() - 1 && str[i] == ' ')
		{
			result += 1;
		}
	}

	cout << result + 1;

	return 0;
}