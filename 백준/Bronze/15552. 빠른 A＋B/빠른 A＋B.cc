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

	int num;
	int x, y;

	cin >> num;

	for (int i = 0; i < num; i++)
	{
		cin >> x >> y;
		cout << x + y << "\n";
	}

	return 0;
}