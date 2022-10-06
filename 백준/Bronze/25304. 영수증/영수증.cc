#include <iostream>
#include <algorithm> 
#include <string> 
// #include <numeric>
// #include <cctype> 
// #include <cmath>
// #include <stack> 
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

	int total;
	int perc_n;
	int price, n;
	int sum = 0;

	cin >> total >> perc_n;

	for (int i = 0; i < perc_n; i++)
	{
		cin >> price >> n;
		sum += price * n;
	}

	if (sum == total)
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}
	return 0;
}
