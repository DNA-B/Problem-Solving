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
	
	int arr[31] = { 0 };
	int student;

	for (int i = 0; i < 28; i++)
	{
		cin >> student;
		arr[student]++;
	}

	for (int i = 1; i < 31; i++)
	{
		if (arr[i] == 0)
		{
			cout << i << "\n";
		}
	}
	return 0;
}