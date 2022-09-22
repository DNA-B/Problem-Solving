#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

// 1259번 : 펠린드롬수
int main()
{
	string str;
	bool flag = true;

	while (1)
	{
		cin >> str;

		if (str == "0")
		{
			return 0;
		}

		for (int i = 0; i < str.size() / 2; i++)
		{
			if (str[i] != str[str.size() - 1 - i])
			{
				flag = false;
			}
		}

		if (flag == true)
		{
			cout << "yes\n";
		}
		else
		{
			cout << "no\n";
		}

		flag = true;
	}
	return 0;
}