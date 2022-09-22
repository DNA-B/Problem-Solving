#include <iostream>
#include <algorithm> 
// #include <string> 
#include <numeric>
// #include <cctype> 
// #include <cmath> 
// #include <queue>
// #include<deque>
// #include <set>
// #include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int x, y;
	cin >> x >> y;
	
	cout << gcd(x, y) << "\n" << lcm(x, y);

	return 0;
}
