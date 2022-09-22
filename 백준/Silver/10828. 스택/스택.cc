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

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<int> st;
	int push_n;
	int rep;
	string order;

	cin >> rep;

	while (rep)
	{
		cin >> order;

		if (order == "push")
		{
			cin >> push_n;
			st.push(push_n);
		}
		else if (order == "pop")
		{
			if (st.empty())
			{
				cout << "-1\n";
				rep--;
				continue;
			}
			cout << st.top() << "\n";
			st.pop();
		}
		else if (order == "top")
		{
			if (st.empty())
			{
				cout << "-1\n";
				rep--;
				continue;
			}
			cout << st.top() << "\n";
		}
		else if (order == "empty")
		{
			if (st.empty())
			{
				cout << "1\n";
			}
			else
			{
				cout << "0\n";
			}
		}
		else if (order == "size")
		{
			cout << st.size() << "\n";
		}
		rep--;
	}

	return 0;
}