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

	int card[5];
	int sum = 0;

	cin >> card[0] >> card[1] >> card[2] >> card[3] >> card[4];
	sum += card[0] + card[1] + card[2] + card[3] + card[4];
	cout << sum;

	return 0;
}
