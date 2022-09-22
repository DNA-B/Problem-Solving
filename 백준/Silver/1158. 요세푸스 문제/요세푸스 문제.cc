#include <iostream>
#include <algorithm> 
#include <string> 
// #include <cctype> 
// #include <cmath> 
// #include <queue>
// #include<deque>
// #include <set>
#include <vector>
#include <list>
// #include <stack> 
// #include <bitset>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	list<int> l;
	list<int>::iterator it;
	int count = 1;
	int n, n_cut;

	cin >> n >> n_cut;

	for (int i = 1; i <= n; i++)
	{
		l.push_back(i);
	}

	it = l.begin();

	cout << '<';
	while (l.size() != 1)
	{
		if (it == l.end())
		{
			it = l.begin();
		}

		if (count % n_cut == 0)
		{
			cout << *it << ", ";
			it = l.erase(it);
			count = 1;
		}
		else
		{
			it++;
			count++;
		}
	}
	cout << l.front() << '>';
	return 0;
}