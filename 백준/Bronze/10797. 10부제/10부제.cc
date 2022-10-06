#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int car[5];
	int day;
	int count = 0;

	cin >> day;
	for (int i = 0; i < 5; i++)
	{
		cin >> car[i];
		if (car[i] == day)
		{
			count++;
		}
	}

	cout << count;

	return 0;
}