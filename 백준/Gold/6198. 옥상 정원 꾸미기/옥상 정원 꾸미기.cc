#include <iostream>
#include <algorithm> 
#include <string> 
// #include <numeric>
// #include <cctype> 
// #include <cmath>
#include <stack> 
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

	int len;
	vector<int> v(1000001);
	stack<pair<int, int>> rooftop;
	long long result = 0;

	cin >> len;

	for (int i = 0; i < len; i++)
	{
		cin >> v[i];
	}

	rooftop.push({ v[len - 1], len });

	for (int i = len - 2; i >= 0; i--)
	{
		while ((rooftop.size() != 0) && (rooftop.top().first < v[i]))
		{
			rooftop.pop();
		}

		if (rooftop.size() == 0)
		{
			result += len - (i + 1);
			rooftop.push({ v[i], i + 1 });
		}
		else
		{
			result += (rooftop.top().second - (i + 1)) - 1;
			rooftop.push({ v[i], i + 1 });
		}
	}

	cout << result;

	return 0;
}