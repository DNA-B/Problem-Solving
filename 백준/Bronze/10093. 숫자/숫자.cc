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
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long a, b;
	long long big, small;

	cin >> a >> b;
    
    if (a == b)
	{
		cout << 0;
		return 0;
	}
    
	big = max(a, b);
	small = min(a, b);

	cout << big - small - 1 << "\n";

	for (long long i = small + 1; i <= big - 1; i++)
	{
		cout << i << " ";
	}

	return 0;
}