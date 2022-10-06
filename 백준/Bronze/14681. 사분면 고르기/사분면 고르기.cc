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

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int x, y;

	cin >> x >> y;

	if (x > 0 && y > 0)
	{
		cout << 1;
	}
	else if(x > 0 && y < 0)
	{
		cout << 4;
	}
	else if (x < 0 && y > 0)
	{
		cout << 2;
	}
	else
	{
		cout << 3;
	}
	return 0;
}