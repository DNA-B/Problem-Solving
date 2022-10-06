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

	long long a, b, c;
	cin >> a >> b >> c;

	cout << (a + b) % c << "\n" << ((a % c) + (b % c)) % c << "\n" << (a * b) % c << "\n" << ((a % c) * (b % c)) % c;
	return 0;
}