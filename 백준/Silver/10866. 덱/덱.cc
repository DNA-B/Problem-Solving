#include <bits/stdc++.h>

using namespace std;

#define PI 3.141592
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	deque<int> d;
	int rep;
	string order;
	int n;

	cin >> rep;

	while (rep--)
	{
		cin >> order;

		if (order == "push_front")
		{
			cin >> n;
			d.push_front(n);
		}
		else if (order == "push_back")
		{
			cin >> n;
			d.push_back(n);
		}
		else if (order == "pop_front")
		{
			if (d.size() == 0)
			{
				cout << "-1\n";
				continue;
			}
			cout << d.front() << "\n";
			d.pop_front();
		}
		else if (order == "pop_back")
		{
			if (d.size() == 0)
			{
				cout << "-1\n";
				continue;
			}
			cout << d.back() << "\n";
			d.pop_back();
		}
		else if (order == "size")
		{
			cout << d.size() << "\n";
		}
		else if (order == "empty")
		{
			if (d.empty())
			{
				cout << "1\n";
				continue;
			}
			else 
			{
				cout << "0\n";
			}
		}
		else if (order == "front")
		{
			if (d.empty())
			{
				cout << "-1\n";
				continue;
			}
			cout << d.front() << "\n";
		}
		else if (order == "back")
		{
			if (d.empty())
			{
				cout << "-1\n";
				continue;
			}
			cout << d.back() << "\n";
		}
	}
	return 0;
}