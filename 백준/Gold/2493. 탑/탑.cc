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

void push_push_baby(vector<int>& v, stack<int>& tower, stack<int>& idx, int vi, int ti, int ii)
{
	v.push_back(vi);
	tower.push(ti);
	idx.push(ii);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<int> tower;
	stack<int> idx;
	vector<int> v;
	int len;
	int num;

	cin >> len;

	for (int i = 0; i < len; i++)
	{
		cin >> num;
		if (i > 0)
		{
			if (tower.top() >= num)
			{
				push_push_baby(v, tower, idx, idx.top(), num, i + 1);
			}
			else
			{
				while (tower.size() > 0)
				{
					if (tower.top() < num)
					{
						tower.pop();
						idx.pop();
					}
					else
					{
						break;
					}
				}

				if (tower.size() == 0)
				{
					push_push_baby(v, tower, idx, 0, num, i + 1);
				}
				else
				{
					push_push_baby(v, tower, idx, idx.top(), num, i + 1);
				}
			}
		}
		else
		{
			push_push_baby(v, tower, idx, 0, num, i + 1);
		}
	}

	for (int n : v)
	{
		cout << n << " ";
	}

	return 0;
}
