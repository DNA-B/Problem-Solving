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

	int n;
	long long sum = 0;

	cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		sum += i;
	}
	cout << sum;
	return 0;
}
