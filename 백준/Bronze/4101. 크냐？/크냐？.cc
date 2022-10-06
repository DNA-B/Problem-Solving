#include <iostream>
#include <algorithm> 
#include <string> 
// #include <numeric>
// #include <cctype> 
// #include <cmath>
// #include <stack> 
// #include <queue>
// #include <deque>
// #include <list>
// #include <set>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int x, y;

	while (1)
	{
		cin >> x >> y;

		if (x == 0 && y == 0)
		{
			return 0;
		}
		else
		{
			if (x > y)
			{
				cout << "Yes\n";
			}
			else
			{
				cout << "No\n";
			}
		}
	}
	return 0;
}
