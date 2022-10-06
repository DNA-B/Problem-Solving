#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm> 
// #include <string> 
// #include <cctype> 
// #include <cmath> 
// #include <queue>
// #include<deque>
// #include <set>
// #include <vector>
// #include <stack> 
// #include <bitset>

using namespace std;

int main()
{
	int d1, d2, d3;
	int prize = 0;

	cin >> d1 >> d2 >> d3;
	
	if (d1 == d2 && d2 == d3)
	{
		prize = 10000 + (d1 * 1000);
	}
	else if (d1 == d2) 
	{
		prize = 1000 + (d1 * 100);
	}
	else if (d1 == d3)
	{
		prize = 1000 + (d1 * 100);
	}
	else if (d2 == d3)
	{
		prize = 1000 + (d2 * 100);
	}
	else
	{
		prize = max({ d1, d2, d3 }) * 100;
	}

	cout << prize;
	return 0;
}