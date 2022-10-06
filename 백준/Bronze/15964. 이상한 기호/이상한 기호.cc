#include <iostream>
#include <algorithm> 
// #include <string> 
// #include <cctype> 
// #include <cmath> 
// #include <queue>
// #include<deque>
// #include <set>
 #include <vector>
// #include <stack> 
// #include <bitset>

using namespace std;

long long golbang(int x, int y)
{
	return (x + y) * (x - y);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int x, y;

	cin >> x >> y;

	cout << golbang(x, y);
	return 0;
}