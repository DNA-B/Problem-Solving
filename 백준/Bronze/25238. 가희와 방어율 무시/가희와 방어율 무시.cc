#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	double guard;
	double player;

	cin >> guard >> player;

	guard -= guard * (player / 100);

	if (guard >= 100)
	{
		cout << "0";
	}
	else
	{
		cout << "1";
	}
	
	return 0;
}