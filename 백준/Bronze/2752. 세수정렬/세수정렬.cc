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
	int arr[3] = { 0 };

	cin >> arr[0] >> arr[1] >> arr[2];

	sort(arr, arr + 3);

	cout << arr[0] << " " << arr[1] << " " << arr[2];

	return 0;
}