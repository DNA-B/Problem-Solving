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
	
	int n;
	long long fact = 1;

	cin >> n;

	for (int i = n; i >= 1; i--)
	{
		fact *= i;
	}

	cout << fact;
	return 0;
}