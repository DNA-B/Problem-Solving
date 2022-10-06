#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int loc;
	int minute;
	
	cin >> loc;
	
	if (loc % 5 == 0)
	{
		cout << loc / 5;
	}
	else
	{
		cout << (loc / 5) + 1;
	}

	return 0;
}