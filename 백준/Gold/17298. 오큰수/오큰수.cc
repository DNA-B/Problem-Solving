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
	stack<int> obign;
	stack<int> result;

	cin >> len;

	for (int i = 0; i < len; i++)
	{
		cin >> v[i];
	}

	obign.push(v[len - 1]);
	result.push(-1);

	for (int i = len - 2; i >= 0; i--)
	{
		while (!(obign.empty()) && (obign.top() <= v[i]))
		{
			obign.pop();
		}

		if (obign.empty())
		{
			result.push(-1);
			obign.push(v[i]);
		}
		else
		{
			result.push(obign.top());
			obign.push(v[i]);
		}
	}

	while (result.size() != 0)
	{
		cout << result.top() << " ";
		result.pop();
	}

	return 0;
}