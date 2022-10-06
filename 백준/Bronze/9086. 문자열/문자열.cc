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
	string str;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> str;
		cout << str[0] << str[str.size() - 1] << "\n";
	}
	return 0;
}