#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<int> q;
	string order;
	int n;
	int rep;

	cin >> rep;

	while(rep--)
	{
		cin >> order;

		if (order == "push")
		{
			cin >> n;
			q.push(n);
		}
		else if (order == "pop")
		{
			if (q.size() == 0)
			{
				cout << "-1\n";
				continue;
			}
			cout << q.front() << "\n";
			q.pop();
		}
		else if (order == "size")
		{
			cout << q.size() << "\n";
		}
		else if (order == "empty")
		{
			if (q.empty())
			{
				cout << "1\n";
			}
			else
			{
				cout << "0\n";
			}
		}
		else if (order == "front")
		{
			if (q.size() == 0)
			{
				cout << "-1\n";
				continue;
			}
			cout << q.front() << "\n";
		}
		else if (order == "back")
		{
			if (q.size() == 0)
			{
				cout << "-1\n";
				continue;
			}
			cout << q.back() << "\n";
		}
	}
	return 0;
}