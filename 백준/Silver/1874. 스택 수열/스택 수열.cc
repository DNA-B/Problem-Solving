#include <iostream>
#include <algorithm> 
#include <string> 
// #include <cctype> 
// #include <cmath> 
// #include <queue>
// #include<deque>
// #include <set>
#include <vector>
// #include <list>
#include <stack> 
// #include <bitset>

using namespace std;

char order[200001] = { '0' };
int seq[100001] = { 0 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<int> st;
	int pos_order = 0;
	int pos_seq = 0;
	int rep;
	int n;

	cin >> rep;

	for (int i = 0; i < rep; i++)
	{
		cin >> seq[i];
	}

	for (int i = 1; i <= rep; i++)
	{
		st.push(i);
		order[pos_order] = '+';
		pos_order++;

		if (st.top() != seq[pos_seq])
		{
			if (st.top() > seq[pos_seq])
			{
				cout << "NO";
				return 0;

			}
		}
		else
		{
			while ((st.size() > 0) && (st.top() == seq[pos_seq]))
			{
				order[pos_order] = '-';
				pos_order++;
				st.pop();
				pos_seq++;
			}
			
			if (!st.empty())
			{
				if (st.top() > seq[pos_seq])
				{
					cout << "NO";
					return 0;
				}
			}
		}
	}

	for (int i = 0; i < pos_order; i++)
	{
		cout << order[i] << "\n";
	}

	return 0;
}