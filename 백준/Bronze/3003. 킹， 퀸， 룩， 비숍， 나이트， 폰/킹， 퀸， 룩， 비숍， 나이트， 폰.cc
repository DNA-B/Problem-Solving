#include <iostream>
#include <algorithm> 
#include <string> 
// #include <numeric>
// #include <cctype> 
// #include <cmath>
// #include <stack> 
// #include <queue>
// #include <deque>
// #include <list>
// #include <set>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int chess[6] = { 1,1,2,2,2,8 };
	int input[6];
	int piece[6] = { 0 };

	for (int i = 0; i < 6; i++)
	{
		cin >> input[i];
	}

	for (int i = 0; i < 6; i++)
	{
		piece[i] = chess[i] - input[i];
	}

	for (int n : piece)
	{
		cout << n << " ";
	}

	return 0;
}
