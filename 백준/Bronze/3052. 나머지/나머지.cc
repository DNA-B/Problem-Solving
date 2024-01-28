#include <bits/stdc++.h>

using namespace std;

int main()
{
	int count[42] = { 0 };
	int x;
	int result = 0;

	for (int i = 0; i < 10; i++)
	{
		cin >> x;
		count[x % 42]++;
	}

	for (int i = 0; i < 42; i++)
	{
		if (count[i] != 0)
			result++;
	}

	cout << result;

	return 0;
}