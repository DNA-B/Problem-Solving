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

	int arr[5];
	int sum = 0;

	for (int i = 0; i <5; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	
	sort(arr, arr + 5);
	
	cout << sum / 5 << endl << arr[2];
	
	return 0;
}