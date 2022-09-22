#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string p;
	int t, len;
	int n;
	char trash;
	bool flag = 1, rev = 0;

	cin >> t;
	while (t--)
	{
		deque<int> d;

		cin.ignore(); // []만 들어왔을 경우도 있으므로 버퍼 비우기
		cin >> p;
		cin >> len;

		for (int i = 1; i <= (2 * len) + 1; i++)
		{
			if (i % 2 == 0)
			{
				cin >> n;
				d.push_back(n);
			}
			else
			{
				cin >> trash;
			}
		}

		for (int i = 0; i < p.size(); i++)
		{
			if (p[i] == 'R')
			{
				if (rev) // reverse 상태
				{
					rev = 0;
				}
				else
				{
					rev = 1;
				}
			}
			else if (p[i] == 'D')
			{
				if (d.size() == 0)
				{
					flag = false;
					break;
				}

				if (rev)
				{
					d.pop_back();
				}
				else
				{
					d.pop_front();
				}

			}
		}

		if (flag == false)
		{
			cout << "error\n";
			flag = 1;
			rev = 0;
			continue;
		}

		if (flag)
		{
			cout << "[";
			while (d.size() != 0)
			{
				if (d.size() == 1)
				{
					cout << d.front();
					break;
				}

				if (rev)
				{
					cout << d.back() << ",";
					d.pop_back();
				}
				else
				{
					cout << d.front() << ",";
					d.pop_front();
				}
			}
			cout << "]\n";
			rev = 0;
		}
		else
		{
			flag = 1;
			rev = 0;
		}
	}
	return 0;
}