#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int N, F, lnum, fnum;
stack<int> st[7];
int cnt = 0;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> F;

	for (int i = 0; i < N; i++)
	{
		cin >> lnum >> fnum;

		if (st[lnum].empty())
		{
			st[lnum].push(fnum);
			cnt++;
		}
		else
		{
			if (st[lnum].top() < fnum)
			{
				st[lnum].push(fnum);
				cnt++;
			}
			else
			{
				while (st[lnum].top() > fnum)
				{
					st[lnum].pop();
					cnt++;

					if (st[lnum].empty())
						break;
				}

				if (!st[lnum].empty() && st[lnum].top() == fnum)
					continue;
				else
				{
					st[lnum].push(fnum);
					cnt++;
				}
			}
		}

	}

	cout << cnt;

	return 0;
}