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

	int count_alp[26] = { 0 };
	string str;

	cin >> str;

	for (int i = 0; i < str.size(); i++)
	{
		count_alp[str[i] - 'a']++;
	}

	for (int i = 0; i < 26; i++)
	{
		cout << count_alp[i] << " ";
	}

	return 0;
}