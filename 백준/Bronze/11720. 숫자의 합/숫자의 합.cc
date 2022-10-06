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
	int n;
	char arr[100] = { '\0' };
	int sum = 0;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		sum += arr[i] - '0';
	}

	cout << sum;

	return 0;
}