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
	int len;
	int standard;
	int arr[10000] = { 0 };
	cin >> len;
	cin >> standard;

	for (int i = 0; i < len; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < len; i++)
	{
		if (arr[i] < standard)
		{
			cout << arr[i] << ' ';
		}
	}
	return 0;
}