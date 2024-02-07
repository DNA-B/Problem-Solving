#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int N, F, lnum, fnum;
set<int, greater<int>> max_fret[7];
int cnt = 0, max = -INT_MAX;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> F;

	for (int i = 0; i < N; i++)
	{
		cin >> lnum >> fnum;

		if (max_fret[lnum].empty())
		{
			max_fret[lnum].insert(fnum);
			cnt++;
		}
		else
		{
			if (max_fret[lnum].find(fnum) != max_fret[lnum].end())
			{
				while (*max_fret[lnum].begin() != fnum)
				{
					max_fret[lnum].erase(max_fret[lnum].begin());
					cnt++;
				}
			}
			else if (*max_fret[lnum].begin() < fnum)
			{
				max_fret[lnum].insert(fnum);
				cnt++;
			}
			else
			{
				while (*max_fret[lnum].begin() > fnum)
				{

					max_fret[lnum].erase(max_fret[lnum].begin());
					cnt++;

					if (max_fret[lnum].empty())
						break;
				}

				max_fret[lnum].insert(fnum);
				cnt++;
			}
		}
	}

	cout << cnt;

	return 0;
}