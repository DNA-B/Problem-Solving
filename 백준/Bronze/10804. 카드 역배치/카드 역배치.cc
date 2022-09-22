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

	int arr[21] = { 0 };
	int start, end;
	int rep = 0;

	for (int i = 1; i < 21; i++)
	{
		arr[i] = i;
	}

	for (int i = 0; i < 10; i++)
	{
		cin >> start >> end;
		rep = (end - start + 1) / 2;

		for (int i = 0; i < rep; i++)
		{
			swap(arr[start + i], arr[end - i]);
		}
	}

	for (int i = 1; i < 21; i++)
	{
		cout << arr[i] << " ";
	}

	return 0;
}