#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int m, d;

	cin >> m >> d;

	if (m == 2 && d == 18)
	{
		cout << "Special";
	}
	else if (m < 2 || (m == 2 && d < 18))
	{
		cout << "Before";
	}
	else if (m > 2 || (m == 2 && d > 18))
	{
		cout << "After";
	}

	return 0;
}