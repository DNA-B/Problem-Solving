#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() 
{
	int a = 0;
	int b = 0;

	while (1)
	{
		cin >> a;
		cin >> b;

		if (a == 0 && b == 0)
		{
			return 0;
		}

		cout << a + b;
		cout << '\n';
	}

	return 0;
}