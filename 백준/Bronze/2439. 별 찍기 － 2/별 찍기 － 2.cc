#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;

	cin >> n;

	for (int i = n; i >= 1; i--)
	{
		for (int j = i - 1; j > 0; j--)
		{
			cout << " ";
		}
		for (int j = i - 1; j < n; j++)
		{
			cout << "*";
		}
		cout << "\n";
	}

	return 0;
}