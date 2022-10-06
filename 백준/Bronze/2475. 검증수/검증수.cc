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
	char arr[6] = { '\0' };
	int result = 0;

	for (int i = 0; i < 5; i++)
	{
		cin >> arr[i];
		result += (arr[i] - '0') * (arr[i] - '0');
	}

	result %= 10;

	cout << result;
	return 0;

}