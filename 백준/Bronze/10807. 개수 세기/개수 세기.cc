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
	int arr[101] = { 0 };
	int freq[201] = { 0 };
	int x;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		freq[arr[i] + 100]++;
	}

	cin >> x;

	cout << freq[x + 100];

	return 0;
}