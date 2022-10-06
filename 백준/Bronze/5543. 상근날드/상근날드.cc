#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int ham[3];
	int cosa[2];
	int price = 0;
	int min = 1000000;

	cin >> ham[0] >> ham[1] >> ham[2] >> cosa[0] >> cosa[1];

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			price = ham[i] + cosa[j] - 50;
			if (min > price)
			{
				min = price;
			}
		}
	}
	
	cout << min;

	return 0;
}